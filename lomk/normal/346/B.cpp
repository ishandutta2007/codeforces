/*input
ABABABB
ABABABB
ABABB
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#define mp make_pair
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 105;

struct State {
  int type;
  int preLen;
  State(int _type, int _preLen) : type(_type), preLen(_preLen) {}
  State() : type(-1), preLen(-1){};
  bool operator<(const State &rhs) const { return preLen < rhs.preLen; }
};

string a, b, virus;

pair<int, State> dp[N][N][N];

int nLenArr[N][26];

int nextLen(int len, char c) { return nLenArr[len][c - 'A']; }

struct KMP {
  vector<int> w;
  string S;
  void init(string _S) {
    S = _S;
    S = "!" + S;
    w.assign(S.size(), 0);
    w[0] = -1;
    w[1] = 0;
    loop(i, 2, S.size() - 1) {
      auto &cur = w[i];
      cur = w[i - 1];
      while (cur != -1) {
        if (S[cur + 1] == S[i])
          break;
        cur = w[cur];
      }
      cur++;
    }
  }
};

int findLongestPrefix(const string &s, const string &t) {
  string m = s + "$" + t;
  KMP kmp;
  kmp.init(m);
  return kmp.w[kmp.S.size() - 1];
}

void prepNLenArr() {
  loop(i, 0, virus.size() - 1) {
    string curStr = virus.substr(0, i);
    for (char c = 'A'; c <= 'Z'; c++) {
      curStr += c;
      nLenArr[i][c - 'A'] = findLongestPrefix(virus, curStr);
      curStr.pop_back();
    }
  }
}

string trace(int endLen) {
  int i = a.size();
  int j = b.size();
  int len = endLen;

  string ret;
  while (true) {
    if (i == 0 || j == 0)
      break;
    auto [type, preLen] = dp[i][j][len].se;
    if (type == 0)
      j--;
    else if (type == 1)
      i--;
    else {
      i--;
      j--;
      ret += a[i];
    }
    len = preLen;
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b >> virus;

  prepNLenArr();

  // dp[0][0][0] = 0;
  loop(i, 0, a.size()) {               // considered the first ith chars of a
    loop(j, 0, b.size()) {             // considered the first jth chars of b
      loop(len, 0, virus.size() - 1) { // string virus is now of size len
        if (j != b.size())
          dp[i][j + 1][len] =
              max(dp[i][j + 1][len], mp(dp[i][j][len].fi, State(0, len)));
        if (i != a.size())
          dp[i + 1][j][len] =
              max(dp[i + 1][j][len], mp(dp[i][j][len].fi, State(1, len)));
        if (i != a.size() && j != b.size() && a[i] == b[j]) {
          int nLen = nextLen(len, a[i]);
          // print(i, j, len, nLen);
          if (nLen != virus.size()) {
            dp[i + 1][j + 1][nLen] =
                max(dp[i + 1][j + 1][nLen],
                    mp(dp[i][j][len].fi + 1, State(2, len)));
          }
        }
      }
    }
  }

  pair<int, int> ans = {0, 0};
  loop(i, 0, virus.size() - 1) ans =
      max(ans, mp(dp[a.size()][b.size()][i].fi, i));

  if (ans.fi == 0) {
    cout << "0" << endl;
    exit(0);
  }
  auto strans = trace(ans.se);
  cout << strans << endl;
}