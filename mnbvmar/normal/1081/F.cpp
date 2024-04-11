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

#ifdef LOCAL
string ans;
string cur;
#endif

int Query(int L, int R) {
#ifdef LOCAL
  int a, b;
  if (rand() % 2) {
    a = 0; b = R - 1;
  } else {
    a = L - 1; b = SZ(cur) - 1;
  }
  for (int i = a; i <= b; ++i)
    cur[i] ^= '0' ^ '1';


  return count(ALL(cur), '1');
#else
  cout << "? " << L << " " << R << endl;
  int v;
  cin >> v;
  return v;
#endif
}

void Answer(VI v) {
#ifdef LOCAL
  string s;
  for (int x : v)
    s += '0' + x;
  debug(s);
  assert(s == ans);
#else
  cout << "! ";
  for (int x : v) cout << x;
  cout << endl;
#endif
  exit(0);
}

int32_t main() {
  srand(time(NULL));
  int N;

  int num_ones;

#ifdef LOCAL
  cin >> ans;
  num_ones = count(ALL(ans), '1');
  cur = ans;
  N = SZ(ans);
#else
  cin >> N >> num_ones;
#endif

  if (N == 1) {
    Answer({num_ones});
  }

  if (N % 2 == 1) {
    vector<int> prefs, sufs;

    for (int pref = 2; pref <= N; pref += 2) {
      int npref;
      while (true) {
        npref = Query(1, pref);
        if (npref % 2 != num_ones % 2) {
          assert(Query(1, N) == num_ones);
          continue;
        }
        break;
      }

      const int diff = num_ones - npref;
      assert(diff % 2 == 0);
      prefs.PB((diff + pref) / 2);

      while (true) {
        npref = Query(1, pref);
        if (npref % 2 != num_ones % 2) {
          Query(1, N);
          continue;
        }
        break;
      }
    }
    debug(prefs);

    for (int suf = 2; suf <= N; suf += 2) {
      int nsuf;
      while (true) {
        nsuf = Query(N - suf + 1, N);
        if (nsuf % 2 != num_ones % 2) {
          assert(Query(1, N) == num_ones);
          continue;
        }
        break;
      }

      const int diff = num_ones - nsuf;
      assert(diff % 2 == 0);
      sufs.PB((diff + suf) / 2);

      while (true) {
        nsuf = Query(N - suf + 1, N);
        if (nsuf % 2 != num_ones % 2) {
          Query(1, N);
          continue;
        }
        break;
      }
    }

    debug(sufs);

    vector<int> data;
    int first = num_ones - sufs.back();

    for (int i = SZ(prefs) - 1; i >= 1; --i)
      prefs[i] -= prefs[i - 1];
    for (int i = SZ(sufs) - 1; i >= 1; --i)
      sufs[i] -= sufs[i - 1];
    reverse(ALL(sufs));
    debug(prefs, sufs);

    data.PB(first);
    for (int i = 1; i < N; ++i) {
      if (i % 2 == 1) {
        data.PB(prefs[i / 2] - data.back());
      } else {
        data.PB(sufs[(i - 1) / 2] - data.back());
      }
    }

    Answer(data);

  } else {
    vector<int> data;

    for (int pos = 1; pos <= N; ++pos) {
      const int pref_par = pos % 2;

      bool has_pref = false, has_suf = false;

      int ans = 0;
      int num_turns = 0;
      int pref_ones = -1, suf_ones = -1;

      while (num_turns % 2 != 0 || !has_pref || !has_suf || ans % 2 != num_ones % 2) {
        ans = Query(pos, pos);
        ++num_turns;
        const int diff = num_ones - ans;

        if (num_turns % 2 == 1 && !has_pref && ans % 2 == (num_ones + pref_par) % 2) {
          pref_ones = (diff + pos) / 2;
          has_pref = true;
        }
        if (num_turns % 2 == 1 && !has_suf && ans % 2 != (num_ones + pref_par) % 2) {
          suf_ones = (diff + (N - pos + 1)) / 2;
          has_suf = true;
        }
      }

      data.PB(pref_ones + suf_ones - num_ones);
    }

    Answer(data);
  }
}