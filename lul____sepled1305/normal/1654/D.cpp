#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 2e5+10;
const int mod = 998244353;

vector<pii> fac[N];
bool not_prime[N];

void sieve() {
    for(int i=2;i<N;i++) {
        if(!not_prime[i]) {
            for(int j=1;j*i<N;j++) {
                int cur = j*i, ct = 0;
                not_prime[cur] = true;
                while(cur % i == 0) {
                    cur /= i;
                    ct ++;
                }
                fac[j*i].push_back({i,ct});
            }
        }
    }
}

int add(int a, int b) {
    return (a+b)%mod;
}

int mul(int a, int b) {
    long long k = (1LL*a*b)%mod;
    return k;
}

int power(int b, int p) {
    if(p == 0) return 1;
    int g = power(b,p/2);
    g = mul(g,g);
    if(p%2) g = mul(g,b);
    return g;
}

int inv(int b) {
    return power(b,mod-2);
}

struct edge{
    int to,x,y;
};
vector<edge> G[N];

int cur[N], mini[N];
bool vis[N];
int ans = 0, rn = 1;
vector<int> change;

void dfs(int node, int par) {
    for(auto it: G[node]) {
        int nxt = it.to;
        if(nxt == par) continue;
        for(auto it: fac[it.x]) {
            cur[it.first] += it.second;
            change.push_back(it.first);
        }
        for(auto it: fac[it.y]) {
            cur[it.first] -= it.second;
            mini[it.first] = min(mini[it.first],cur[it.first]);
            change.push_back(it.first);
        }
//        cout<<node<<' '<<it.to<<' '<<it.x<<' '<<it.y<<endl;
        dfs(nxt,node);
        for(auto it: fac[it.x]) {
            cur[it.first] -= it.second;
            change.push_back(it.first);
        }
        for(auto it: fac[it.y]) {
            cur[it.first] += it.second;
            change.push_back(it.first);
        }
    }
}

int dfs2(int node, int par) {
    ans = add(ans,rn);
    for(auto it: G[node]) {
        int nxt = it.to;
        if(nxt == par) continue;
        rn = mul(rn,it.x);
        rn = mul(rn,inv(it.y));
        dfs2(nxt,node);
        rn = mul(rn,it.y);
        rn = mul(rn,inv(it.x));
    }
}

int main() {
    sieve();
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=0;i<n-1;i++) {
            int a,b,x,y; cin>>a>>b>>x>>y;
            G[a-1].push_back({b-1,y,x});
            G[b-1].push_back({a-1,x,y});
        }
        //Now DFS from node 0
        dfs(0,0);
        //Answer now saved in mini
        for(auto it: change) {
            if(vis[it]) continue;
            vis[it] = true;
            rn = mul(rn,power(it,-mini[it]));
        }
//        cout<<rn<<endl;
        dfs2(0,0);
        cout<<ans<<'\n';
        for(auto it: change)
            cur[it] = 0, mini[it] = 0, vis[it] = false;
        ans = 0, rn = 1;
        change.clear();
    }
    return 0;
}