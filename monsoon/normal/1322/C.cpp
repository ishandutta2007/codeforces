#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 5100000;
int _,n,m;
ll c[N],rnd[N],hasz[N];
vector<int> adj[N];

int main() {
  mt19937_64 rng(time(0));
  uniform_int_distribution<ll> dis;
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d%d",&n,&m);
    REP(i,n) scanf("%lld",&c[i]);
    REP(i,m) {
      int a,b; scanf("%d%d",&a,&b); --a;--b;
      adj[a].push_back(b);
    }

    REP(i,n) {
      rnd[i] = dis(rng);
      hasz[i] = 0;
    }


    REP(i,n) {
      for (auto u : adj[i]) hasz[u] ^= rnd[i];
    }

    map<ll,ll> mapa;
    REP(i,n) mapa[hasz[i]] += c[i];

    ll ans = 0;
    for (auto u : mapa) if (u.first) {
      ans = __gcd(ans, u.second);
    }

    printf("%lld\n",ans);

    REP(i,n) adj[i].clear();
  }
}