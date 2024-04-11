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


const int MaxN = 500 * 1000;
const int LogMaxN = 20;

int ParentMain[MaxN][LogMaxN];
int MaxWeight[MaxN][LogMaxN];
int Weight[MaxN];

int ParentAux[MaxN][LogMaxN];
int SumWeights[MaxN][LogMaxN];
int HeightAux[MaxN];

int S;


void addNode(int R, int W) {
  ++S;
  Weight[S] = W;
  ParentMain[S][0] = R;
  MaxWeight[S][0] = Weight[R];
  for (int i = 1; i < LogMaxN; ++i) {
    ParentMain[S][i] = ParentMain[ParentMain[S][i - 1]][i - 1];
    MaxWeight[S][i] = max(MaxWeight[S][i - 1],
                          MaxWeight[ParentMain[S][i - 1]][i - 1]);
  }

  int Pnt = S;
  for (int i = LogMaxN - 1; i >= 0; --i) {
    if (MaxWeight[Pnt][i] >= W) { continue; }
    Pnt = ParentMain[Pnt][i];
  }

  debug(Pnt, W, ParentMain[Pnt][0], Weight[1]);

  if (Weight[ParentMain[Pnt][0]] >= W)
    Pnt = ParentMain[Pnt][0];
  else
    Pnt = S;

  ParentAux[S][0] = Pnt;
  SumWeights[S][0] = Pnt == S ? 0 : Weight[Pnt];
  HeightAux[S] = Pnt == S ? 0 : HeightAux[Pnt] + 1;
  debug(S, Pnt, SumWeights[S][0]);
  for (int i = 1; i < LogMaxN; ++i) {
    ParentAux[S][i] = ParentAux[ParentAux[S][i - 1]][i - 1];
    SumWeights[S][i] = SumWeights[S][i - 1] + SumWeights[ParentAux[S][i - 1]][i - 1];
  }
}

int queryNode(int R, int W) {
  if (Weight[R] > W) { return 0; }

  int Result = 1;
  W -= Weight[R];
  for (int i = LogMaxN - 1; i >= 0; --i) {
    int p = ParentAux[R][i];
    debug(R, i, p, SumWeights[R][i]);
    if (HeightAux[R] - HeightAux[p] != (1 << i)) { continue; }
    if (SumWeights[R][i] > W) { continue; }
    W -= SumWeights[R][i];
    R = p;
    Result += (1 << i);
  }
  return Result;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int Q;
  cin >> Q;
  int last = 0;

  for (int i = 0; i < LogMaxN; ++i)
    ParentMain[1][i] = 1;
  S = 1;

  for (int i = 0; i < Q; ++i) {
    int type, p, q;
    cin >> type >> p >> q;
    p ^= last; q ^= last;
    debug(type, p, q);

    if (type == 1)
      addNode(p, q);
    else {
      last = queryNode(p, q);
      debug(last);
      cout << last << "\n";
    }
  }
}