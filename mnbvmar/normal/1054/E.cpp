#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
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

int N, M;

#warning REVERSE

vector<PII> Make01(vector<vector<string>> board) {
  vector<PII> answer;

  vector<vector<string>> col_board(N, vector<string>(M));

  auto MoveTo = [&](int r1, int c1, int r2, int c2) {
    assert(r1 == r2 || c1 == c2);
    answer.emplace_back(r1, c1);
    answer.emplace_back(r2, c2);
  };


  for (int col = 0; col < M; ++col) {
    for (int row = 0; row < N; ++row) {
      for (char ch : board[row][col]) {
        if (col != ch - '0') {
          MoveTo(row, col, row, ch - '0');
          col_board[row][ch - '0'] += ch;
        } else {
          const int dest_row = row ? row - 1 : row + 1;
          MoveTo(row, col, dest_row, col);
          col_board[dest_row][col] += ch;
        }
      }
    }
  }

  for (int col : {0, 1})
    for (int row = 1; row < N; ++row)
      for (int i = 0; i < SZ(col_board[row][col]); ++i)
        MoveTo(row, col, 0, col);

  return answer;
}

void Read(vector<vector<string>> &r, bool rev) {
  for (auto &row : r)
    for (auto &col : row) {
      cin >> col;
      if (rev)
        reverse(ALL(col));
    }
}

queue<char> cur_board[340][340];

void Dbg() {
#ifdef LOCAL
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      queue<char> q = cur_board[i][j];
      string s;
      while (!q.empty()) { s += q.front(); q.pop(); }
      cerr << s << " ";
    }
    cerr << "\n";
  }
#endif
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;
  vector<vector<string>> board_src(N, vector<string>(M));
  vector<vector<string>> board_dest(N, vector<string>(M));

  Read(board_src, true);
  Read(board_dest, false);

  auto moves_src = Make01(board_src);
  auto moves_dest = Make01(board_dest);
  copy(moves_dest.rbegin(), moves_dest.rend(), back_inserter(moves_src));

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      for (char ch : board_src[i][j])
        cur_board[i][j].push(ch);

  const int S = SZ(moves_src) / 2;
  cout << S << "\n";
  for (int i = 0; i < S; ++i) {
    const int t = i * 2;
    const auto [r1, c1] = moves_src[t];
    const auto [r2, c2] = moves_src[t+1];

    debug(r1, c1, r2, c2);
    assert(!cur_board[r1][c1].empty());
    const auto ch = cur_board[r1][c1].front();
    cur_board[r1][c1].pop();
    cur_board[r2][c2].push(ch);
    cout << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << "\n";
    Dbg();
  }

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      string s;
      auto &q = cur_board[i][j];
      while (!q.empty()) { s += q.front(); q.pop(); }
      reverse(ALL(s));
      assert(s == board_dest[i][j]);
    }
}