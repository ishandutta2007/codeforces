#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int x,y;
    ll c;
    bool operator < (const node &a)const{
        return c < a.c;
    }
};
vector<node> v;
int n,x[2020],y[2020],par[2020],chk[2020];
ll c[2020],k[2020],ans;
vector<int> v1;
vector<pair<int,int>> v2;
int f(int a){
    if(a == par[a]) return a;
    return par[a] = f(par[a]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=1;i<=n;i++) scanf("%d %d",x+i,y+i);
    for(int i=1;i<=n;i++) scanf("%lld",c+i);
    for(int i=1;i<=n;i++) scanf("%lld",k+i);

    for(int i=1;i<=n;i++) v.push_back({0, i, c[i]});
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) v.push_back({i, j, (k[i]+k[j]) * (abs(x[i]-x[j]) + abs(y[i]-y[j]))});
    sort(v.begin(), v.end());
    
    for(auto u : v){
        if(u.x == 0){
            int cur = f(u.y);
            if(!chk[cur]){
                chk[cur] = 1;
                ans += u.c;
                v1.push_back(u.y);
            }
        }else{
            int X = f(u.x), Y = f(u.y);
            if(X == Y || (chk[X] && chk[Y])) continue;

            if(chk[X]) swap(X, Y);
            par[X] = Y;
            ans += u.c;

            v2.push_back({u.x, u.y});
        }
    }

    printf("%lld",ans);
    printf("\n%d",v1.size());
    if(v1.size()){
        puts("");
        for(auto u : v1) printf("%d ",u);
    }
    printf("\n%d",v2.size());
    if(v2.size()){
        puts("");
      for(auto u : v2) printf("%d %d\n",u.first,u.second);
    }
}