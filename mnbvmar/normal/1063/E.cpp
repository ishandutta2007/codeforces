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


const int MaxN = 1024;

int N;
int order[MaxN];
int prev_order[MaxN];
bool visited[MaxN];

VI GetCycle(int x) {
  assert(!visited[x]);
  VI answer;
  do {
    visited[x] = true;
    answer.push_back(x);
    x = prev_order[x];
  } while (x != answer[0]);
  return answer;
}

vector<string> last_answer;
vector<string> answer;

void MoveRibbon(string &s, int from, int to) {
  assert(from != to);
  if (from < to) {
    s[from] = s[to] = '\\';
  } else {
    s[from] = s[to] = '/';
  }
}

void SolveFirst() {
  auto cyc0 = GetCycle(0);
  const int S = SZ(cyc0);

  for (int i = S - 1; i > 0; --i) {
    const int cur = cyc0[i];
    const int nxt = cyc0[(i + 1) % S];
    string line(N, '.');
    MoveRibbon(line, cur, nxt);
    last_answer.push_back(line);
  }
}

void SolveOther(int base) {
  if (visited[base]) { return; }
  auto cycle = GetCycle(base);
  const int S = SZ(cycle);
  if (S == 1) { return; }

  string first_line(N, '.');
  MoveRibbon(first_line, base, 0);
  MoveRibbon(first_line, cycle.back(), base);
  answer.push_back(first_line);

  cycle[0] = 0;

  for (int d = S - 1; d > 0; --d) {
    const int src = cycle[d - 1];
    const int dest = cycle[d];
    string line(N, '.');
    MoveRibbon(line, src, dest);
    answer.push_back(line);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  int num_matching = 0;
  for (int i = 0; i < N; ++i) {
    cin >> order[i];
    --order[i];
    prev_order[order[i]] = i;
    num_matching += order[i] == i;
  }

  if (num_matching == N) {
    cout << N << "\n";
    for (int i = 0; i < N; ++i)
      cout << string(N, '.') << "\n";
    return 0;
  }

  SolveFirst();
  for (int fst = 1; fst < N; ++fst)
    SolveOther(fst);

  for (string s : last_answer)
    answer.PB(s);

  while ((int)answer.size() != N)
    answer.push_back(string(N, '.'));

  cout << N - 1 << "\n";
  for (auto &s : answer)
    cout << s << "\n";

}