#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define R(i,n) for(int i = 0; i < (n); i++)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
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

template<class T> ostream &operator<<(ostream& os, set<T> V) {
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

int n,l;

int odl(int a,int b){
  if(a > b)swap(a,b);
  //debug(a,b, min(b - a, l - b + a));
  return min(b - a, l - b + a);
}
bool spr(vector<int> &a,vector<int>& b, int x,bool=1){
  int ak = n-1;
  auto xxx = [&](int pom){
    if(pom >= l)pom -= l;
    if(pom >= l - x) pom -= l;
    return pom;
  };
  R(i,2 * n){
    if(i && (a[i] - a[i-1] + l) % l + xxx(a[i-1] - b[ak] + l) <= x){
      ak++;
      if(odl(a[i],b[ak]) > x)return 0;
    }else{
      int kon = (a[i] + x) % l;
      int naj = -1, kt = 0;
      while(ak < 2 * n && odl(a[i],b[ak]) <= x){
        int odll = (kon - b[ak] + l) % l;
        if(odll > naj || (odll == naj && ak % n < kt % n)){
          kt = ak;
          naj = odll;
        }
        ak++;
      }
      if(ak == 2 * n){
        ak = kt;
      }else{
        while(ak < 2 * n && odl(a[i],b[ak]) > x){
          ak++;
        }
        if(ak == 2 * n)return 0;
      }
    }
    if(ak >= n)ak -= n;
  }
  return 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> l;
  vector<int> a(n),b(n);
  a.resize(n);
  b.resize(n);
  R(i,n){
    cin >> a[i];
  }
  sort(ALL(a));
  a.resize(2*n);
  R(i,n){
    cin >> b[i];
  }
  sort(ALL(b));
  b.resize(2*n);
  R(i,n){
    a[i + n] = a[i];
    b[i + n] = b[i];
  }
  int po = -1, ko = l / 2;
  while((po + 1) != ko){
    int m = (po + ko)/2;
    if(spr(a,b,m) && spr(b,a,m)){
      ko = m;
    }else{
      po = m;
    }
  }
  debug(a,b);
  debug(spr(a,b,42,1));
  
  cout << ko << "\n";
}