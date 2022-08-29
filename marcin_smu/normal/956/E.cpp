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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int MAX = 10101;
int n,l,r;
// bitset<MAX> plec;
int plec[MAX];
int a[MAX],res[MAX];
vector<int> dob;
void add(int x,int jak){
//   plec |= plec << x;
  for(int i = MAX - x - 1; i >= 0; i--){
    mini(plec[i + x], plec[i] + jak);
  }
}
int get(int x){
  if(x < 0)return 0;
  return res[x];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> l >> r;
  R(i,n){
    cin >> a[i];
  }
//   debug(plec._Find_first());
  R(i,MAX)plec[i] = 1e9;
  plec[0] = 0;
//   assert(plec._Find_first() == 0);
  R(i,n){
    int pom;
    cin >> pom;
    if(pom){
      dob.PB(a[i]);
    }else{
      add(a[i],0);
    }
  }
  sort(ALL(dob));
  R(i,10){
    cerr << plec[i] << " ";
  }
  cerr << "\n";
  debug(dob);
  int j = 0,sum = 0;
  R(i,MAX){
    if(j < SZ(dob) && sum + dob[j] <= i){
      sum += dob[j];
      j++;
    }
    res[i] = j+1;
  }
  int wyn = 0;
  int added = 0;
  while(1){
//     maxi(wyn, min(SZ(dob), get(r - l - ((plec >> l)._Find_first()))));
//     debug(wyn, SZ(dob), r , (plec >> l)._Find_first());
    for(int i = l; i <= r; i++)if(plec[i] < added){
      maxi(wyn, min(res[r - i], SZ(dob) + 1));
    }else if(plec[i] == added){
      maxi(wyn, min(res[r - i], SZ(dob)));
    }
    if(SZ(dob) <= wyn)break;
    added++;
    add(dob.back(),1);
    dob.pop_back();
  }
  cout << wyn << "\n";
}