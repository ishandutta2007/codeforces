#include <bits/stdc++.h>

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

template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<endl;}
template<class TH, class...TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<",";_dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


char board[2][14];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  string s;
  cin >> s;
  const int N = 27;

  for (char ch = 'A'; ch <= 'Z'; ch++) {
    if (count(ALL(s), ch) == 1) { continue; }
    debug(s, ch);

    int fst = 30, last = -1;
    for (int i = 0; i < N; i++) {
      if (s[i] == ch) {
        maxi(last, i); mini(fst, i);
      }
    }
    debug(fst, last);

    int len = last - fst - 1;
    if (len == 0) {
      cout << "Impossible\n";
      return 0;
    }

    int row = 0, col = len / 2, ptr = fst + 1;
    board[row][col] = ch;

    while (ptr != last) {
      if (row == 0) {
        if (col == 0) {
          row = 1;
        } else {
          col--;
        }
      } else {
        col++;
      }
      debug(row, col, ptr);
      board[row][col] = s[ptr++];
    }

    ptr = (ptr + 1) % N;

    while (ptr != fst) {
      if (row == 1) {
        if (col == 12) {
          row = 0;
        } else {
          col++;
        }
      } else {
        col--;
      }

      board[row][col] = s[ptr];
      ptr = (ptr + 1) % N;
    }
  }

  cout << board[0] << "\n" << board[1] << "\n";
}