#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LD long double
#define LL long long
#define int LL
#define FI first
#define SE second
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "[";
  for (auto& tt : V) { os << tt << ","; }
  os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  int pl = 1,mi = 0;
  vector<char> zn;
  zn.PB('+');
  while(1){
    char q,z;
    cin >> q >> z;
    if(z == '='){
      break;
    }
    zn.PB(z);
    if(z == '+')
      pl++;
    else
      mi++;
  }
  int n;
  cin >> n;
  int bil = n - pl + mi;
  string res = "";
  R(i,SZ(zn)){
    if(i){
      res += " ";
      res += zn[i];
      res += " ";
    }
    if(zn[i] == '+'){
      int il = max(min(n-1,bil),0ll);
      bil -= il;
      res += to_string(il+1);
    }else{
      int il = max(min(n-1,-bil),0ll);
      bil += il;
      res += to_string(il+1);
    }
  }
  res += " = ";
  res += to_string(n);
  if(bil == 0){
    cout << "Possible\n";
    cout << res << endl;
  }else{
    cout << "Impossible\n";
  }
}