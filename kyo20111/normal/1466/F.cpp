#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n, m, col[500500], chk[500500], par[500500];
ll ans, mod = 1e9 + 7;
set<int> s[500500];
 
int find(int a){
    if(a == par[a]) return a;
    return par[a] = find(par[a]);
}
 
int merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return 0;
    if(s[a].size() > s[b].size()) swap(a, b);
    for(auto x : s[a]) s[b].insert(x);
    par[a] = b;
    return 1;
}
 
ll pw(ll n, ll k){
    if(!k) return 1;
    ll re = pw(n, k/2) % mod;
    return re * re % mod * (k % 2 ? n : 1) % mod;
}
 
int main(){
    scanf("%d %d",&n,&m);
 
    for(int i=1;i<=m;i++) par[i] = i, s[i].insert(i);
 
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        if(a == 1){
            int b; scanf("%d",&b);
            if(!col[b]){
                for(auto x : s[find(b)]) col[x] = 1;
                chk[i] = 1;
            }
        }else{
            int b, c; scanf("%d %d",&b,&c);
            if(col[b]) swap(b, c);
 
            if(!col[b] && !col[c] && merge(b, c)){
                chk[i] = 1;
            }else if(!col[b] && col[c]){
                for(auto x : s[find(b)]) col[x] = 1;
                chk[i] = 1;
            }
        }
    }
 
    int cnt = 0;
    for(int i=1;i<=n;i++) if(chk[i]) cnt++;
    printf("%lld %d\n",pw(2, cnt),cnt);
    for(int i=1;i<=n;i++) if(chk[i]) printf("%d ",i);
}