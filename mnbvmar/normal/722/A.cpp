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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  string dt;
  int nhrs;
  cin >> nhrs >> dt;

  string best = ".....";
  int bestDist = 100;

  int fh = 0, th = 24;
  if (nhrs == 12) { fh = 1; th = 13; }

  for (int h = fh; h < th; h++) {
    for (int m = 0; m < 60; m++) {
      string hstr = to_string(h), mstr = to_string(m);
      while (SZ(hstr) < 2) { hstr = "0" + hstr; }
      while (SZ(mstr) < 2) { mstr = "0" + mstr; }

      string cmpd = hstr + ":" + mstr;

      int dist = 0;
      for (int i = 0; i < 5; i++) {
        if (dt[i] != cmpd[i]) { dist++; }
      }
      if (dist < bestDist) {
        bestDist = dist;
        best = cmpd;
      }
    }
  }

  cout << best << endl;
}