#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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


const int Mod = 1e9 + 7;
const int Infty = 1e9 + 15;


struct SegTree {
  struct Node {
    vector<int> balls;
  };

  vector<Node> data;
  int Base;

  vector<int> hgtBalls;
  vector<int> cntBalls;
  vector<bool> removed;

  SegTree(int N) : Base(1) {
    while (Base < N + 5) { Base *= 2; }
    data.resize(Base * 2);
  }

  LL doPops(int v, int h) {
    LL result = 0;
    while (SZ(data[v].balls) && hgtBalls[data[v].balls.back()] <= h) {
      int which = data[v].balls.back();
      if (!removed[which]) {
        result += cntBalls[data[v].balls.back()];
        removed[which] = true;
      }
      data[v].balls.pop_back();
    }
    return result % Mod;
  }


  int fetch(int left, int right, int maxHeight) {
    left += Base; right += Base;
    LL result = doPops(left, maxHeight) + doPops(right, maxHeight);
    while (left / 2 != right / 2) {
      if (left % 2 == 0) { result += doPops(left + 1, maxHeight); }
      if (right % 2 == 1) { result += doPops(right - 1, maxHeight); }
      left /= 2; right /= 2;
    }
    return result % Mod;
  }

  void putBall(int pos, int h, int cnt) {
    int id = SZ(cntBalls);
    removed.push_back(false);
    cntBalls.push_back(cnt);
    hgtBalls.push_back(h);

    pos += Base;
    while (pos > 0) {
      data[pos].balls.push_back(id);
      pos /= 2;
    }
  }
};


const int MaxN = 1e5 + 6;
int barU[MaxN], barL[MaxN], barR[MaxN], barS[MaxN];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int H, W, N;
  cin >> H >> W >> N;
  SegTree tree(W + 10);

  for (int i = 1; i <= W; i++) {
    tree.putBall(i, H + 1, 1);
  }

  for (int i = 0; i < N; i++) {
    cin >> barU[i] >> barL[i] >> barR[i] >> barS[i];
  }

  vector<int> order(N);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int lhs, int rhs) {
        return barU[lhs] > barU[rhs];
      });

  for (int i : order) {
    int cnt = tree.fetch(barL[i], barR[i], barU[i] + barS[i]);
    debug(i, cnt);
    
    if (barL[i] == 1) {
      tree.putBall(barR[i] + 1, barU[i], (cnt * 2) % Mod);
    } else if (barR[i] == W) {
      tree.putBall(barL[i] - 1, barU[i], (cnt * 2) % Mod);
    } else {
      tree.putBall(barL[i] - 1, barU[i], cnt);
      tree.putBall(barR[i] + 1, barU[i], cnt);
    }
    
  }

  cout << tree.fetch(1, W, Infty) << "\n";
}