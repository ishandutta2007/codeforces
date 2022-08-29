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
#define MAX 100010
int m = 0;
int res[MAX],dp[MAX];
vector<PII> zap[MAX];
int dl(){
  string z;
  cin >> z;
  return SZ(z);
}

const int P = 1e9 + 7;
int odw[MAX];
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w&1){
      r = r * a %P;
    }
    w/=2;
    a = a*a%P;
  }
  return r;
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  int q;
  cin >> q;
  int ak = dl();
  R(i,q){
    int co;
    cin >> co;
    if(co == 1){
      ak = dl();
    }else{
      int n;cin >> n;
      zap[ak].PB({n,m++});
    }
  }
  R(i,MAX)odw[i] = pot(i,P-2);
  debug(odw[1],odw[2]);
  R(dl,MAX){
    if(SZ(zap[dl])){
      R(i,dl)dp[i] = 0;
      int pom = 1;
      int sum = 0;
      for(int i = dl; i < MAX; i++){
        sum *= 26;
        sum += pom;
        sum %= P;
        dp[i] = sum;
        
        pom = (pom * 25)%P * i%P * odw[i-dl+1]%P;
      }
      for(auto x:zap[dl]){
        res[x.SE] = dp[x.FI];
      }
    }
  }
  R(i,m){
    cout << res[i] << "\n";
  }
  
  
}