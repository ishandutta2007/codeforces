#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

vector<vector<int>> cycle_decomposition(const vector<int>& a) {
  const int n = a.size();
  vector<char> visited(n);
  vector<vector<int>> res;
  for(int i = 0; i < n; i++) if (!visited[i]) {
    res.emplace_back();
    auto& vs = res.back();
    int v = i;
    do {
      visited[v] = true;
      vs.push_back(v);
      v = a[v];
    } while (v != i);
  }
  return res;
}

constexpr int B = 320;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  VI p(n);
  rep(i, n) cin >> p[i], p[i]--;
  VI a(n), pos_in_a(n);
  set<int> st;
  rep(i, q) {
    if (i % B == 0) {
      st.clear();
      auto cs = cycle_decomposition(p);
      int p = 0;
      for(auto& c : cs) {
        for(int i : c) {
          a[p] = i;
          pos_in_a[i] = p;
          p++;
        }
        st.insert(p - 1);
      }
      // rep(i, n) cout << a[i] << " ";
      // cout << endl;
    }
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      swap(p[x], p[y]);
      st.insert(pos_in_a[x]);
      st.insert(pos_in_a[y]);
    } else {
      int i, k;
      cin >> i >> k;
      i--;
      if (p[i] == i) {
        cout << i + 1 << '\n';
        continue;
      }
      // get_cycle_len
      const int ia = pos_in_a[i];
      int now = ia;
      int len = 0;
      now = pos_in_a[p[a[now]]];
      len++;

      while(true) {
        // cout << now << ' ' << len << endl;
        int ib = *st.lower_bound(now);
        if (now <= ia && ia <= ib) {
          len += ia - now;
          break;
        }
        len += ib - now;
        now = ib;
        // cout << "!"<< ' ' << len << ' ' << ib << ' ' << now << endl;
        now = pos_in_a[p[a[now]]];
        len++;
        // cout << "!"<< ' ' << len << ' ' << ib << ' ' << now << endl;
        // exit(0);
      }
      k %= len;
      
      // cout << len<< endl;
      // exit(0);
      if (k == 0) {
        cout << i + 1 << '\n';
        continue;
      }
      now = ia;
      while(true) {
        int ib = *st.lower_bound(now);
        int l = ib - now;
        if (l >= k) {
          cout << a[now + k] + 1 << '\n';
          break;
        }
        now = ib;
        k -= l;
        now = pos_in_a[p[a[now]]];
        k--;
        if (k == 0) {
          cout << a[now] + 1 << '\n';
          break;
        }
      }
    }
  }
}