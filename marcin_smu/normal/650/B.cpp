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

#define MAX 500100
int n,a,b,t;
string z;
int sp[MAX];
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n >> a >> b >> t >> z;
  int res = 0;
  R(_,2){
    F(i,1,n){
      sp[i+1] = sp[i] + (z[i] == 'h'?1+a:1+a+b);
    }
    int sum = 1;
    if(z[0] == 'w')
      sum += b;
    if(sum <= t)
      maxi(res,1ll);
    for(int i = n-1;i >= 0;i--){
      if(z[i] == 'h'){
        sum += 1+a;
      }else{
        sum += 1+a+b;
      }
      debug(sum);
      if(sum > t)break;
      int il = n-i;
      int po = 1, ko = n+2;
      while(po+1 != ko){
        int m = (po+ko)/2;
        if(sp[m] + sum + il * a <= t)
          po = m;
        else
          ko = m;
      }
      maxi(res,il + po);
    }
    reverse(z.begin()+1,z.end());
  }
  mini(res,n);
  cout << res << endl;
}