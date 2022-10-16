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

const int MaxN = 3048;

int N;
string word_from[MaxN], word_to[MaxN];

int FindAt(const string &text, const string &needle) {
  string s = needle + "#" + text;
  const int L = SZ(s);
  vector<int> K(L + 1);

  for (int i = 2; i <= L; ++i) {
    const int ch = s[i - 1];
    K[i] = K[i - 1];
    while (K[i] && ch != s[K[i]])
      K[i] = K[K[i]];
    if (ch == s[K[i]])
      ++K[i];

    if (K[i] == SZ(needle))
      return i - SZ(needle) * 2 - 1;
  }
  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> word_from[i];
  for (int i = 0; i < N; ++i)
    cin >> word_to[i];

  vector<int> bad_words, good_words;
  vector<int> pos_start(N), pos_end(N);
  string repl_from, repl_to;

  for (int i = 0; i < N; ++i) {
    if (word_from[i] == word_to[i]) { good_words.PB(i); continue; }

    int lptr = 0, rptr = SZ(word_to[i]) - 1;
    while (word_from[i][lptr] == word_to[i][lptr]) { ++lptr; }
    while (word_from[i][rptr] == word_to[i][rptr]) { --rptr; }
    ++rptr;

    const string my_from = word_from[i].substr(lptr, rptr - lptr);
    const string my_to = word_to[i].substr(lptr, rptr - lptr);

    if (repl_from != "") {
      if (repl_from != my_from || repl_to != my_to) {
        cout << "NO\n";
        return 0;
      }
    } else {
      repl_from = my_from;
      repl_to = my_to;
    }

    bad_words.push_back(i);
    pos_start[i] = lptr;
    pos_end[i] = rptr;
  }

  debug(repl_from, repl_to);

  auto HasSameLetter = [&](int idx) {
    char needed_from = 0, needed_to = 0;
    for (int w : bad_words) {
      const int ptr = pos_start[w] + idx;
      if (ptr < 0 || ptr >= SZ(word_from[w])) { return false; }

      const char ch_from = word_from[w][ptr];
      const char ch_to = word_to[w][ptr];
      if (!needed_from) {
        needed_to = ch_to;
        needed_from = ch_from;
      } else if (needed_from != ch_from || needed_to != ch_to) {
        return false;
      }
    }
    return true;
  };

  while (true) {
    if (!HasSameLetter(-1)) { break; }
    for (int w : bad_words)
      --pos_start[w];
  }
  const int w0 = bad_words[0];
  while (true) {
    const int cur_len = pos_end[w0] - pos_start[w0];
    if (!HasSameLetter(cur_len)) { break; }
    for (int w : bad_words)
      ++pos_end[w];
  }

  repl_from = word_from[w0].substr(pos_start[w0], pos_end[w0] - pos_start[w0]);
  repl_to = word_to[w0].substr(pos_start[w0], pos_end[w0] - pos_start[w0]);

  debug(repl_from, repl_to);

  for (int w : bad_words) {
    const int pos = FindAt(word_from[w], repl_from);
    if (pos != pos_start[w]) {
      cout << "NO\n";
      return 0;
    }
  }

  for (int w : good_words)
    if (FindAt(word_from[w], repl_from) != -1) {
      cout << "NO\n";
      return 0;
    }

  cout << "YES\n";
  cout << repl_from << "\n";
  cout << repl_to << "\n";

}