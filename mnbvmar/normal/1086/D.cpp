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


struct Tree {
  int Base;
  vector<int> data;

  Tree(int N) : Base(1) {
    while (Base < N + 2) { Base *= 2; }
    data.resize(Base * 2);
  }

  void Add(int v, int p) {
    v += Base;
    while (v) {
      data[v] += p;
      v /= 2;
    }
  }

  int GetSum(int L, int R) {
    if (L > R) { return 0; }
    L += Base; R += Base;
    if (L == R) { return data[L]; }
    int ans = data[L] + data[R];

    while (L / 2 != R / 2) {
      if (L % 2 == 0) { ans += data[L + 1]; }
      if (R % 2 == 1) { ans += data[R - 1]; }
      L /= 2; R /= 2;
    }
    return ans;
  }
};

int N, Q;
VI cur_setup;
set<int> all_vals[3];
int mapping[256];
vector<Tree> trees;

int GetResult() {
  int ans = N;

  for (int type : {0, 1, 2}) {
    const int winning = (type + 1) % 3;
    const int losing = (type + 2) % 3;

    if (!all_vals[losing].empty()) {
      if (all_vals[winning].empty()) {
        ans -= SZ(all_vals[type]);
      } else {
        const int first_lose = *all_vals[losing].begin();
        const int last_lose = *all_vals[losing].rbegin();
        const int first_win = *all_vals[winning].begin();
        const int last_win = *all_vals[winning].rbegin();

        if (first_lose < first_win) {
          ans -= trees[type].GetSum(first_lose, first_win);
        }
        if (last_lose > last_win) {
          ans -= trees[type].GetSum(last_win, last_lose);
        }
      }

    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> Q;
  mapping[(int)'R'] = 0;
  mapping[(int)'S'] = 1;
  mapping[(int)'P'] = 2;

  trees.resize(3, Tree(N + 2));

  for (int i = 0; i < N; ++i) {
    char ch;
    cin >> ch;
    const int val = mapping[(int)ch];
    trees[val].Add(i, 1);
    all_vals[val].insert(i);
    cur_setup.PB(val);
  }

  cout << GetResult() << "\n";

  for (int i = 0; i < Q; ++i) {
    int pos;
    char ch;
    cin >> pos >> ch;
    --pos;
    const int old_val = cur_setup[pos];
    const int new_val = mapping[(int)ch];

    debug(pos, old_val, new_val);

    trees[old_val].Add(pos, -1);
    all_vals[old_val].erase(pos);
    trees[new_val].Add(pos, 1);
    all_vals[new_val].insert(pos);
    cur_setup[pos] = new_val;

    cout << GetResult() << "\n";
    debug(cur_setup);
#ifdef LOCAL
    for (int j = 0; j < 3; ++j) {
      debug(vector<int>(ALL(all_vals[j])));
    }
#endif
  }

}