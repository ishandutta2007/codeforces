#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

const int M = 10;
using ULL = uint64_t;

struct SumUnits {
  array<ULL, M> value;

  SumUnits() { value.fill(0); }

  SumUnits(ULL x) {
    value.fill(0);
    value[0] = x;
  }

  SumUnits &operator+=(const SumUnits &other) {
    for (int i = 0; i < M; ++i) {
      value[i] += other.value[i];
    }
    return *this;
  }

  SumUnits &operator-=(const SumUnits &other) {
    for (int i = 0; i < M; ++i) {
      value[i] -= other.value[i];
    }
    return *this;
  }

  SumUnits operator*(const SumUnits &other) const {
    SumUnits ans;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        ans.value[(i + j) % M] += value[i] * other.value[j];
      }
    }
    return ans;
  }

  SumUnits PowMod(int n) const {
    SumUnits ans(1);
    SumUnits val = *this;
    //debug(ans, val, val*val);
    while (n) {
      if (n & 1) { ans = ans * val; }
      n >>= 1;
      val = val * val;
    }
    return ans;
  }

  SumUnits Shift(int x) const {
    SumUnits ans;
    for (int i = 0; i < M; ++i) {
      ans.value[(i + x) % M] = value[i];
    }
    return ans;
  }

  friend ostream &operator<<(ostream &os, const SumUnits &su) {
    os<<"[";
    for (int i = 0; i < M; ++i) { os<<su.value[i]<<','; }
    return os<<"]";
  }

  ULL GetInt() const {
    SumUnits cpy = *this;
    ULL v = cpy.value[1];
    for (int i = 0; i < M; ++i) {
      cpy.value[i] -= v;
    }
    v = cpy.value[2];
    for (int i = 0; i < M; i += 2) {
      cpy.value[i] -= v;
    }
    v = cpy.value[5];
    for (int i = 0; i < M; i += 5) {
      cpy.value[i] -= v;
    }
    for (int i = 1; i < M; ++i) {
      assert(cpy.value[i] == 0);
    }
    return cpy.value[0];
  }
};

#warning
const int MaxRange = 1e5;

SumUnits values[MaxRange + 5];

void DoDFT(int coef, bool invert) {
  const int dir = invert ? M - 1 : 1;

  for (int base = 0; base < MaxRange; ++base) {
    if (base % (coef * 10) >= coef) { continue; }

    int ids[M];
    for (int i = 0; i < M; ++i) {
      ids[i] = base + i * coef;
    }

    SumUnits su[M];
    for (int i = 0; i < M; ++i) {
      su[i] = SumUnits{};
    }

    for (int i = 0; i < M; ++i) {
      //const int k = ids[i];
      for (int j = 0; j < M; ++j) {
        const int n = ids[j];
        su[i] += values[n].Shift((i * j * dir) % M);
      }
    }

    for (int i = 0; i < M; ++i) {
      const int k = ids[i];
      values[k] = su[i];
    }
  }

#ifdef LOCAL
  for (int i = 0; i < 10; ++i) {
    cerr << values[i] << ",";
  }
  cerr << "\n";
#endif
}

int N;

const ULL Inv5 = 57646075230342349ULL;
const ULL Mod = 1ULL << 58;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    ++values[v].value[0];
  }

  for (int coef = 1; coef < MaxRange; coef *= 10) {
    DoDFT(coef, false);
  }

  //debug(values[0], values[1]);

  for (int i = 0; i < MaxRange; ++i) {
    values[i] = values[i].PowMod(N);
  }

#ifdef LOCAL
  for (int i = 0; i < 10; ++i) {
    cerr << values[i] << ",";
  }
  cerr << "\n";
#endif


  for (int coef = 1; coef < MaxRange; coef *= 10) {
    DoDFT(coef, true);
  }

  //debug(values[0], values[1]);

  vector<ULL> answers(N);
  for (int i = 0; i < N; ++i) {
    answers[i] = values[i].GetInt();
  }

  for (int coef = 1; coef < MaxRange; coef *= 10) {
    for (ULL &x : answers) {
      x /= 2;
      x *= Inv5;
    }
  }

  for (ULL x : answers) {
    x %= Mod;
    cout << x << "\n";
  }
}