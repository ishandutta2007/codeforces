#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0) cout
#endif

typedef long double D;

#define MAX 101

D tra[MAX],p[MAX];

D ileda(int i){
  return (1 - tra[i]) * p[i] / tra[i];
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  
  int n;
  cin >> n;
  R(i,n){
    cin >> p[i];
    p[i] /= 100;
    tra[i] = p[i];
  }
  D res = 0;
  D ost = 0;
  F(i,n,1000000){
    D ak = 1;
    R(i,n)ak *= tra[i];
    D naj = -1;
    int kt = 0;
    R(i,n){
      D pom = ileda(i); 
      if(pom > naj){
        naj = pom;
        kt = i;
      }
    }
    tra[kt] += (1 - tra[kt]) * p[kt];
    res += (ak - ost) * i;
    ost = ak;
  }
  
  cout << res << endl;
}