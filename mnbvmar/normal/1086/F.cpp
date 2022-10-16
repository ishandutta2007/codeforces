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

const int Mod = 998'244'353;

int PowMod(int a, int n) {
  int r = 1;
  while (n) {
    if (n & 1) { r = (LL)r * a % Mod; }
    n >>= 1;
    a = (LL)a * a % Mod;
  }
  return r;
}

struct Point {
  int x, y;
};

const int MaxN = 64;

Point pts[MaxN];
int N, T;

LL GetNumCovered(int tm) {
  struct Event {
    int x;
    int y1, y2;
    int coef;

    bool operator<(const Event &other) const {
      return x < other.x;
    }
  };
  
  vector<int> all_ys;

  vector<Event> events;
  for (int i = 0; i < N; ++i) {
    events.push_back(Event{pts[i].x - tm, pts[i].y - tm, pts[i].y + tm + 1, 1});
    events.push_back(Event{pts[i].x + tm + 1, pts[i].y - tm, pts[i].y + tm + 1, -1});
    all_ys.PB(pts[i].y + tm + 1);
    all_ys.PB(pts[i].y - tm);
  }

  sort(ALL(events));
  sort(ALL(all_ys));
  all_ys.resize(unique(ALL(all_ys)) - all_ys.begin());
  vector<int> count_covers(SZ(all_ys));

  int last_x = -1e9;
  LL answer = 0;
  LL total_y = 0;

  for (auto &event : events) {
    const int x = event.x;
    answer += (x - last_x) * total_y;
    last_x = x;

    const int start_y = lower_bound(ALL(all_ys), event.y1) - all_ys.begin();
    const int end_y = lower_bound(ALL(all_ys), event.y2) - all_ys.begin();
    
    for (int i = start_y; i < end_y; ++i)
      count_covers[i] += event.coef;

    total_y = 0;
    for (int i = 0; i < SZ(all_ys) - 1; ++i) {
      if (count_covers[i]) {
        total_y += all_ys[i + 1] - all_ys[i];
      }
    }

    //debug(all_ys, count_covers);
  }

  return answer;
}

LL GetIncrNumCovered(int tm) {
  return GetNumCovered(tm) - GetNumCovered(tm - 1);
}

const int Inv2 = PowMod(2, Mod - 2);
const int Inv6 = PowMod(6, Mod - 2);

int SumQuad(int A, int B, int C, int n) {
  LL ans = (LL)C * n % Mod;
  LL bcoef = (n * (n + 1)) % Mod * Inv2 % Mod;
  ans = (ans + bcoef * B) % Mod;
  LL acoef = (n * (n + 1)) % Mod * (2 * n + 1) % Mod * Inv6 % Mod;
  ans = (ans + acoef * A) % Mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> T;
  for (int i = 0; i < N; ++i) {
    cin >> pts[i].x >> pts[i].y;
  }

  int cur_tm = 2;
  LL p0 = GetIncrNumCovered(2);
  LL p1 = GetIncrNumCovered(1);
  debug(p0, p1);
  LL answer = 0;
  if (T >= 1) { answer = (answer + p1) % Mod; }
  if (T >= 2) { answer = (answer + 2LL * p0) % Mod; }
  if (T <= 2) {
    cout << answer << "\n";
    return 0;
  }
  
  while (cur_tm < T) {
    int left_lin = cur_tm;
    int right_lin = T;

    while (right_lin - left_lin > 1) {
      const int mid_lin = (left_lin + right_lin) / 2;
      const LL pmid = GetIncrNumCovered(mid_lin);
      debug(p0, p1, mid_lin, pmid);

      if (p0 + (mid_lin - cur_tm) * (p0 - p1) == pmid) {
        left_lin = mid_lin;
      } else {
        right_lin = mid_lin;
      }
    }

    debug(left_lin);
    const LL A = (p0 - p1) % Mod;
    const LL B = (p0 + cur_tm * (p0 - p1)) % Mod;
    const LL C = (p0 % Mod) * cur_tm % Mod;

    debug(A, B, C);
    answer = (answer + SumQuad(A, B, C, left_lin - cur_tm)) % Mod;

    p1 = GetIncrNumCovered(left_lin);
    p0 = GetIncrNumCovered(left_lin + 1);
    cur_tm = left_lin + 1;
    answer = (answer + (LL)(p0 % Mod * cur_tm)) % Mod;
    debug(cur_tm, answer);
  }

  cout << answer << "\n";
}