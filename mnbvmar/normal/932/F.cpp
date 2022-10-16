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

const int MaxN = 1e5 + 100;

int N;
LL ui[MaxN], vi[MaxN];
vector<int> Adj[MaxN];


struct Slopes {
  vector<tuple<LL, LL, LL>> Lines;


  Slopes(vector<pair<LL, LL>> Data) {
    sort(ALL(Data), [&](const pair<LL,LL> &lhs, const pair<LL,LL> &rhs) {
          return MP(lhs.st, -lhs.nd) > MP(rhs.st, -rhs.nd);
        });
    debug(Data);
    int S = SZ(Data);
    Lines.reserve(S);
    Lines.emplace_back(Data[0].st, Data[0].nd, (LL)(-1e18));

    for (int i = 1; i < S; ++i) {
      if (Data[i].st == get<0>(Lines.back())) { continue; }
      while (SZ(Lines) >= 2) {
        auto &A = Lines[SZ(Lines) - 2], &B = Lines.back();
        auto &C = Data[i];
        LL Aa = get<0>(A), Ab = get<1>(A);
        LD CutAC = (LD)(C.nd - Ab) / (Aa - C.st);
        debug("here", CutAC);
        if (C.st * CutAC + C.nd <= get<0>(B) * CutAC + get<1>(B)) {
          Lines.pop_back();
          continue;
        }
        break;
      }
      auto &A = Lines.back();
      auto &C = Data[i];
      LL Aa = get<0>(A), Ab = get<1>(A);
      LD CutAC = (LD)(C.nd - Ab) / (Aa - C.st);
      debug("there", CutAC);
      Lines.emplace_back(Data[i].st, Data[i].nd, (LL)ceil(CutAC));
    }
  }

  bool operator<(const Slopes &Other) const {
    return size() < Other.size();
  }

  int size() const { return SZ(Lines); }

  LL operator()(LL x) const {
    int lptr = -1, rptr = size();
    while (rptr - lptr > 1) {
      int mid = (lptr + rptr) / 2;
      if (mid < size() - 1 && get<2>(Lines[mid + 1]) <= x)
        lptr = mid;
      else if (get<2>(Lines[mid]) > x)
        rptr = mid;
      else
        return get<0>(Lines[mid]) * x + get<1>(Lines[mid]);
    }
    assert(false);
  }
};


multiset<Slopes> X[MaxN];
int Result[MaxN];
int TreeSize[MaxN];

void dfs(int v, int p) {
  TreeSize[v] = 1;
  PII Largest{0, 0};

  for (int s : Adj[v]) {
    if (s == p) { continue; }
    dfs(s, v);
    maxi(Largest, MP(TreeSize[s], s));
  }

  if (Largest.st == 0) {
    vector<PII> ToPush;
    ToPush.emplace_back(vi[v], 0LL);
    X[v].emplace(ToPush);
    return;
  }

  X[v].swap(X[Largest.nd]);
  for (int s : Adj[v]) {
    if (s == p || s == Largest.nd) { continue; }
    for (auto &S : X[s])
      X[v].insert(S);
    X[s].clear();
  }

  Result[v] = 1e18;
  cerr << v << " -> ";
  for (auto &S : X[v]) {
    for (auto &L : S.Lines)
      cerr << get<0>(L) << ":" << get<1>(L) << ":" << get<2>(L) << "***";
    cerr << "  ";
    mini(Result[v], S(ui[v]));
  }
  cerr << "\n";

  multiset<Slopes>::iterator It = X[v].begin(), ItDel = X[v].begin();
  int CurSum = 0;
  while (It != X[v].end()) {
    if (CurSum >= It->size())
      ItDel = next(It);
    CurSum += It->size();
    ++It;
  }

  vector<pair<int, int>> ToPush;
  ToPush.reserve(CurSum + 1);
  for (auto ItX = X[v].begin(); ItX != ItDel; ++ItX)
    for (auto &L : ItX->Lines)
      ToPush.emplace_back(get<0>(L), get<1>(L));
  ToPush.emplace_back(vi[v], Result[v]);

  X[v].erase(X[v].begin(), ItDel);
  X[v].emplace(ToPush);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 1; i <= N; ++i) { cin >> ui[i]; }
  for (int i = 1; i <= N; ++i) { cin >> vi[i]; }
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    Adj[u].PB(v);
    Adj[v].PB(u);
  }

  dfs(1, 1);
  for (int i = 1; i <= N; ++i)
    cout << Result[i] << " ";
  cout << "\n";

}