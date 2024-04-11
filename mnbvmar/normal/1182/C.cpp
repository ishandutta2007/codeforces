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

int n;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> n;

  multiset<string> words;
  map<pair<int, char>, vector<string>> last_words;

  const string kPattern = "aeoiu";

  auto GetVowels = [&](string s) {
    string ans;
    for (char ch : s) {
      if (kPattern.find(ch) != string::npos) {
        ans += ch;
      }
    }
    return ans;
  };

  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    words.insert(s);
    string vowels = GetVowels(s);
    last_words[pii(SZ(vowels), vowels.back())].PB(s);
  }

  vector<pair<string, string>> firsts, lasts;
  vector<string> rems;
  for (auto &&[info, vec] : last_words) {
    (void)info;
    const int S = SZ(vec);
    for (int i = 1; i < S; i += 2) {
      lasts.emplace_back(vec[i - 1], vec[i]);
    }
    if (S % 2 == 1) {
      rems.PB(vec.back());
    }
  }

  map<int, vector<string>> first_words;
  for (string rem : rems) {
    string vowels = GetVowels(rem);
    first_words[SZ(vowels)].PB(rem);
  }

  for (auto &&[info, vec] : first_words) {
    (void)info;
    const int S = SZ(vec);
    for (int i = 1; i < S; i += 2) {
      firsts.emplace_back(vec[i - 1], vec[i]);
    }
  }

  const int sol_size = min(SZ(lasts), (SZ(firsts) + SZ(lasts)) / 2);
  while (SZ(firsts) < sol_size) {
    firsts.PB(lasts.back());
    lasts.pop_back();
  }

  cout << sol_size << "\n";
  for (int i = 0; i < sol_size; ++i) {
    cout << firsts[i].st << " " << lasts[i].st << "\n";
    cout << firsts[i].nd << " " << lasts[i].nd << "\n";
  }
}