#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define int ll
void solution() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i ++)
    cin >> x[i];
  int cnt = 0;
  vector<map<int, int>> id(n + 1);
  vector<vector<pair<int, int>>> g(k * 2 + 5);
  id[1][1] = ++cnt;
  id[n][m] = ++cnt;
  for (int i = 0; i < k; i ++) {
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;
    if (!id[a][b]) id[a][b] = ++ cnt;
    if (!id[c][d]) id[c][d] = ++ cnt;
    g[id[a][b]].emplace_back(id[c][d], -h);
  }
  for (int i = 1; i <= n; i ++) {
    auto it = id[i].begin();
    int prv, pid;
    if (it != id[i].end()) {
      prv = it->first;
      pid = it->second;
      it ++;
    }
    while (it != id[i].end()) {
      g[pid].emplace_back(it->second, abs(it->first - prv) * x[i]);
      g[it->second].emplace_back(pid, abs(it->first - prv) * x[i]);
      prv = it->first;
      pid = it->second;
      it ++;
    }
  }

  vector<int> accessed(cnt + 1, 0);
  int frontL = 2, frontR = int(sqrt(cnt + 5));

//spfa+mcfx

    constexpr int INF = 1e18;
    vector<int> dist(cnt + 1, INF);
    vector<bool> in(cnt + 1);
    deque<int> q{1};
    dist[1] = 0;
    in[1] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop_front();
        in[u] = 0;
        for(auto& [v, w]: g[u]) if(dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            if(!in[v]) {
                in[v] = 1;
                int tmp = ++accessed[v];
                if(frontL <= tmp && tmp <= frontR) q.push_front(v);
                else q.push_back(v);
            }
        }
    }

    if (dist[id[n][m]] == INF) cout << "NO ESCAPE";
    else cout << dist[id[n][m]];
    cout << endl;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) solution();
}