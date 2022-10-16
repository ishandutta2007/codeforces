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

const int MaxDp = 3e6 + 100;

int N, M1, M2, T;
vector<int> Important;

int MaxTime[MaxDp][2];
bool ChangeRow[MaxDp][2];
bool Locked[MaxDp][2];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M1 >> M2 >> T;
  vector<vector<int>> Obstacles(2);
  Obstacles[0].resize(M1);
  Obstacles[1].resize(M2);

  for (auto &V : Obstacles)
    for (int &x : V)
      cin >> x;

  Important.reserve(3 * (M1 + M2) + 1);
  Important.push_back(0);

  auto addImportant = [&](int x) {
    for (int t : {x - 1, x, x + 1}) {
      if (SZ(Important) > 0 && Important.back() >= t) { continue; }
      Important.push_back(t);
    }
  };

  int Lptr = 0, Rptr = 0;
  while (Lptr < M1 || Rptr < M2) {
    bool TakeLeft = Rptr == M2;
    if (Lptr < M1 && Rptr < M2)
      TakeLeft |= Obstacles[0][Lptr] < Obstacles[1][Rptr];

    if (TakeLeft)
      addImportant(Obstacles[0][Lptr++]);
    else
      addImportant(Obstacles[1][Rptr++]);
  }

  debug(Important);
  int S = SZ(Important);

  const int Infty = 2e9;

  MaxTime[0][0] = -T;
  MaxTime[0][1] = -T;
  ChangeRow[0][1] = true;

  Lptr = 0; Rptr = 0;
  for (int i = 1; i < S; ++i) {
    int x = Important[i];
    int dx = x - Important[i - 1];
    bool LockedL = (Lptr < M1 && Obstacles[0][Lptr] == x);
    bool LockedR = (Rptr < M2 && Obstacles[1][Rptr] == x);
    if (LockedL) { ++Lptr; }
    if (LockedR) { ++Rptr; }
    Locked[i][0] = LockedL;
    Locked[i][1] = LockedR;
    debug(LockedL, LockedR);

    // Row unchanged?
    for (int b : {0, 1}) {
      MaxTime[i][b] = MaxTime[i - 1][b] + dx;
      if (Locked[i][b]) {
        if (MaxTime[i][b] <= 0)
          MaxTime[i][b] = -Infty;
        else
          MaxTime[i][b] -= T;
      }
    }

    // Change rows?
    for (int b : {0, 1}) {
      if (Locked[i][b]) { continue; }
      int tt = MaxTime[i][b ^ 1];
      int NewT = min<LL>(tt, 0);
      if (NewT > MaxTime[i][b]) {
        MaxTime[i][b] = NewT;
        ChangeRow[i][b] = true;
      }
    }

    debug(i, MaxTime[i][0], MaxTime[i][1]);
  }

  auto checkWin = [&](int i, int b) {
    if (MaxTime[i][b] < -T) { return; }
    cout << "Yes\n";
    vector<int> Changes;
    vector<PII> Shots;
    int NumToShoot = 0;

    auto settleShots = [&]() {
      int x = Important[i];
      int AmountWait = -MaxTime[i][b];
      assert(AmountWait >= 0);
      int FirstShot = x + AmountWait;
      while (NumToShoot > 0) {
        --NumToShoot;
        Shots.emplace_back(FirstShot + NumToShoot * T, b + 1);
      }
    };

    while (!(i == 0 && b == 0)) {
      if (ChangeRow[i][b]) {
        settleShots();
        Changes.push_back(Important[i]);
        b ^= 1;
        NumToShoot = Locked[i][b];
      } else {
        --i;
        NumToShoot += Locked[i][b];
      }
    }

    settleShots();

    cout << SZ(Changes) << "\n";
    reverse(ALL(Changes));
    for (int v : Changes) { cout << v << " "; }
    cout << "\n";
    cout << SZ(Shots) << "\n";
    reverse(ALL(Shots));
    for (auto &P : Shots)
      cout << P.first << " " << P.second << "\n";


    exit(0);
  };

  checkWin(S - 1, 0);
  checkWin(S - 1, 1);

  cout << "No\n";
}