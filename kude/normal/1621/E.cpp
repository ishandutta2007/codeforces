#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
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


template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
  int n;
  vector<int> floor_lg;
  vector<vector<S>> d;
  SparseTable() {}
  explicit SparseTable(vector<S>&& a): n(a.size()), floor_lg(n + 1) {
    if (n == 0) return;
    int frog = 0;
    for(int i = 1; i <= n; frog++) {
      int j = min(n + 1, 2 * i);
      for(; i < j; i++) floor_lg[i] = frog;
    }
    d.resize(frog);
    d[0] = move(a);
    for(int p = 0, w = 1; p < frog - 1; p++, w *= 2) {
      int last = n - 2 * w;
      d[p + 1].resize(last + 1);
      for(int i = 0; i <= last; i++) d[p + 1][i] = op(d[p][i], d[p][i + w]);
    }
  }
  explicit SparseTable(const vector<S>& a): SparseTable(vector<S>(a)) {}

  S query(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return e();
    int w = r - l;
    int p = floor_lg[w];
    return op(d[p][l], d[p][r - (1 << p)]);
  }
};

char op(char f, char g) { return f && g; }
char e() { return true; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VL a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));
        a.erase(a.begin(), a.begin() + n - m);
        VVL b(m);
        VL k(m);
        VL s(m);
        rep(i, m) {
            cin >> k[i];
            b[i].resize(k[i]);
            rep(j, k[i]) cin >> b[i][j];
            s[i] = accumulate(all(b[i]), 0LL);
        }
        VI ord(m);
        iota(all(ord), 0);
        sort(all(ord), [&](int i, int j) {
            // s[i]/k[i] < s[j]/k[j]
            return s[i] * k[j] < s[j] * k[i];
        });
        VI rank(m);
        rep(i, m) rank[ord[i]] = i;
        vector<char> d0(m, true), d_shl(m, true), d_shr(m, true);
        rep(i, m) {
            int x = ord[i];
            // s[x]/k[x] <= a[i]
            d0[i] = s[x] <= a[i] * k[x];
        }
        rep(i, m) if (i) {
            int x = ord[i];
            d_shl[i] = s[x] <= a[i-1] * k[x];
        }
        rep(i, m - 1) {
            int x = ord[i];
            d_shr[i] = s[x] <= a[i+1] * k[x];
        }
        SparseTable<char, op, e> q0(d0), q_shl(d_shl), q_shr(d_shr);
        string ans;
        rep(i, m) rep(j, k[i]) {
            ll nk = k[i] - 1;
            ll ns = s[i] - b[i][j];
            int lb = -1, ub = m;
            while(ub - lb > 1) {
                int c = (lb + ub) / 2;
                int j = ord[c];
                // ns/nk<=s[j]/k[j]
                if (ns * k[j] <= s[j] * nk) {
                    ub = c;
                } else {
                    lb = c;
                }
            }
            if (rank[i] == lb || rank[i] == ub) {
                ans += "01"[
                    q0.query(0, rank[i]) &&
                    // ns/nk <= a[rank[i]]
                    ns <= a[rank[i]] * nk && 
                    q0.query(rank[i] + 1, m)];
            } else if (rank[i] < lb) {
                ans += "01"[
                    q0.query(0, rank[i]) &&
                    q_shl.query(rank[i] + 1, ub) &&
                    // ns/nk <= a[lb]
                    ns <= a[lb] * nk &&
                    q0.query(ub, m)];
            } else {
                ans += "01"[
                    q0.query(0, ub) &&
                    // ns/nk <= a[ub]
                    ns <= a[ub] * nk &&
                    q_shr.query(ub + 1, rank[i]) &&
                    q0.query(rank[i] + 1, m)];
            }
        }
        cout << ans << '\n';
    }
}