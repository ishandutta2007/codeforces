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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

int N;


int ask(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) { return 0; }
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  int x;
  cin >> x;
  return x;
}


bool findAny(int *coords, int minRects) {
  int coord[4] = {coords[0], coords[1], coords[2], coords[3]};
  if (ask(coord[0], coord[1], coord[2], coord[3]) < minRects) { return false; }

  for (int c = 0; c < 4; c++) {
    int ncoord[4];
    for (int j = 0; j < 4; j++) { ncoord[j] = coord[j]; }

    int from = min(coord[c], coord[c^2]), to = max(coord[c], coord[c^2]);
    from--; to++;

    while (from < to - 1) {
      int mid = (from + to) / 2;
      ncoord[c] = mid;

      bool fail = ask(ncoord[0], ncoord[1], ncoord[2], ncoord[3]) < minRects;
      bool incr = fail ^ (c < 2);
      if (incr) {
        from = mid;
      } else {
        to = mid;
      }
    }

    coord[c] = from + (c >= 2);
  }

  for (int i = 0; i < 4; i++) { coords[i] = coord[i]; }
  return true;
}


int32_t main() {
  cin >> N;
  int coord[4] = {1, 1, N, N};

  assert(findAny(coord, 1));
  int res[4] = {coord[0], coord[1], coord[2], coord[3]};

  for (int c = 0; c < 4; c++) {
    coord[0] = 1;
    coord[1] = 1;
    coord[2] = N;
    coord[3] = N;
    switch (c) {
      case 0: coord[0] = res[2] + 1; break;
      case 1: coord[1] = res[3] + 1; break;
      case 2: coord[2] = res[0] - 1; break;
      case 3: coord[3] = res[1] - 1; break;
    }
    if (findAny(coord, 1)) {
      cout << "! " << coord[0] << " " << coord[1] << " " << coord[2] << " " << coord[3] << " ";
      cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;
      return 0;
    }
  }
  assert(false);
}