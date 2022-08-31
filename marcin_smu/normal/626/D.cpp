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

#define MAX 20010
typedef long double D;
int n;
int t[MAX];
int roz[MAX];
int par[MAX];
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n;
  R(i,n){
    cin >> t[i];
  }
  sort(t,t+n);
  R(i,n)R(j,i){
    roz[t[i] - t[j]]++;
  }
  R(i,6000)R(j,6000){
    par[i+j] += roz[i] * roz[j];
  }
  int sum = 0;
  int res = 0;
  R(i,10000){
    res += sum * roz[i];
    sum += par[i];
  }
  debug(res,sum);
  int pom = n * (n-1) / 2;
  cout << D(res) / pom / pom / pom << endl;
}