#include<bits/stdc++.h>
#define maxn 600000
using namespace std;
long long mod[2];
long long b[2];
long long step(long long x,long long y,int i) {
    if(y==0) return 1ll;
    if(y&1ll) return (x*(step(x,y-1,i)))%mod[i];
    else return step((x*x)%mod[i],y>>1ll,i);
}
map<pair<long long,long long>,long long> mp;
int t;
int n,m;
long long c[maxn];
vector<int> a[maxn];
long long deg[2][maxn];
void calc_deg() {
    deg[0][0]=deg[1][0]=1;
    for(int i=1;i<maxn;i++) {
        deg[0][i]=(b[0]*deg[0][i-1])%mod[0];
        deg[1][i]=(b[1]*deg[1][i-1])%mod[1];
    }
}
int main() {
    mod[0]=1e9+7;
    mod[1]=998244353;
    b[0]=1000007;
    b[1]=100007;
    calc_deg();
    scanf("%d",&t);
    while(t--) {
        mp.clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
        int u,v;
        for(int i=0;i<m;i++) {
            scanf("%d %d",&u,&v);
            a[v].push_back(u);
        }
        for(int i=1;i<=n;i++) {
            long long s0=0,s1=0;
            if(a[i].size()==0) continue;
            for(auto t:a[i]) {
                s0=(s0+deg[0][t])%mod[0];
                s1=(s1+deg[1][t])%mod[1];
            }
            mp[{s0,s1}]+=c[i];
        }
        long long g=0;
        for(auto t:mp) {
            if(g==0) g=t.second;
            else g=__gcd(g,t.second);
        }
        for(int i=1;i<=n;i++) a[i].clear();
        printf("%lld\n",g);
    }
    return 0;
}