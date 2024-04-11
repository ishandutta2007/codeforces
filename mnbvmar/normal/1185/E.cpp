#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;


char sss[1000 * 1000 + 10];

string ReadWord() {
  scanf("%s", sss);
  return sss;
}

const int A = 26;

struct Testcase {
  vector<string> final_board;
  vector<string> board;
  int n, m;
  vi minr, maxr, minc, maxc;
  
  void Draw(char ch, int r1, int c1, int r2, int c2) {
    for (int r = r1; r <= r2; ++r) {
      for (int c = c1; c <= c2; ++c) {
        board[r][c] = ch;
      }
    }
  }
  
  void Run() {
    scanf("%d%d", &n, &m);
    final_board.resize(n);
    for (string &s : final_board) { s = ReadWord(); }
    
    minr.resize(A, 1e9);
    maxr.resize(A, -1e9);
    minc.resize(A, 1e9);
    maxc.resize(A, -1e9);
    int maxd = 0;
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        const char ch = final_board[i][j];
        if (ch == '.') { continue; }
        const int d = ch - 'a';
        maxi(maxd, d + 1);
        mini(minr[d], i); maxi(maxr[d], i);
        mini(minc[d], j); maxi(maxc[d], j);
      }
    }
    
    vector<vi> ans;
    board.resize(n, string(m, '.'));
    
    for (int d = 0; d < maxd; ++d) {
      debug(d, minr[d], maxr[d], minc[d], maxc[d]);
      if (minr[d] > maxr[d]) {
        ans.PB(vi{-1, -1, -1, -1});
        continue;
      }
      if (minr[d] != maxr[d] && minc[d] != maxc[d]) {
        printf("NO\n");
        return;
      }
      Draw('a' + d, minr[d], minc[d], maxr[d], maxc[d]);
      ans.PB(vi{minr[d]+1, minc[d]+1, maxr[d]+1, maxc[d]+1});
    }
    
    if (board == final_board) {
      printf("YES\n%d\n", maxd);
      for (int i = maxd - 2; i >= 0; --i) {
        if (ans[i][0] == -1) {
          ans[i] = ans[i + 1];
        }
      }
      for (auto &row : ans) {
        for (int x : row) { printf("%d ", x); }
        printf("\n");
      }
    } else {
      printf("NO\n");
    }
  }
};

int32_t main() {
  int t;
  scanf("%d", &t);
  while (t--) { Testcase().Run(); }
}