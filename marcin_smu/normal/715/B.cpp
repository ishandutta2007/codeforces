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

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
#define MAX 10010

int n,m,l,s,t;
int a[MAX],b[MAX],c[MAX],odl[MAX];
vector<int> kt;
int licz(int xx){
  R(i,SZ(kt)){
    c[kt[i]] = 1 + (xx / SZ(kt) + (i < xx % SZ(kt)));
  }
  R(i,n)odl[i] = l+1;
  odl[s] = 0;
  R(_,n+1)R(i,m){
    if(odl[b[i]] + c[i] < odl[a[i]])
      odl[a[i]] = odl[b[i]] + c[i];
    if(odl[a[i]] + c[i] < odl[b[i]])
      odl[b[i]] = odl[a[i]] + c[i];
  }
  if(odl[t] == l){
    cout << "YES\n";
    R(i,m){
      cout << a[i] << " " << b[i] << " " << c[i] << "\n";
    }
    exit(0);
  }
  return odl[t];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> l >> s >> t;
  R(i,m){
    cin >> a[i] >> b[i] >> c[i];
    if(c[i] == 0){
      kt.PB(i);
    }
  }
  int po = -1,ko = SZ(kt) * ((int)1e10) + 5;
  while(po+1 != ko){
    int m = (po + ko)/2;
    if(licz(m) > l)
      ko = m;
    else
      po = m;
  }
  cout << "NO\n";
}