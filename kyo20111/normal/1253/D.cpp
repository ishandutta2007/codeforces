#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,par[200200],chk[200200],l,r,fl;
pair<int,int> p[200200];
ll ans;
int f(int a){
    if(a == par[a]) return a;
    return par[a] = f(par[a]);
}
void uni(int a,int b){
    a = f(a), b = f(b);
    par[a] = b;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=1;i<=m;i++) scanf("%d %d",&p[i].first,&p[i].second);
    for(int i=1;i<=m;i++) if(p[i].first > p[i].second) swap(p[i].first, p[i].second);
    sort(p+1, p+1+m);
    p[m+1].first = 1e9;
    l = p[1].first, r = p[1].second;
    uni(l, r);
    for(int i=2;i<=m+1;i++){
        if(r < p[i].first){
            int cnt = 0;
            for(int j=l;j<=r;j++){
               int u = f(j);
                if(!chk[u]) cnt++;
                chk[u] = 1;
            }
            ans += cnt-1;
            l = p[i].first, r = p[i].second;
        }else{
            r = max(r, p[i].second);
        }

        if(i <= m) uni(p[i].first, p[i].second);
    }
    printf("%lld",ans);
}