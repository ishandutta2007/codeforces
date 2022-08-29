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

#define MAX 200001
int n,k,a,b,q;
int dp[2][MAX];
void dod(int kt, int a, int il){
  debug(kt,a,il);
  a++;
  for(;a <= n;a+=(a&-a))
    dp[kt][a]+=il;
}
int sum(int kt,int a){
  debug(kt,a);
  int res = 0;
  for(;a;a-=(a&-a))
    res += dp[kt][a];
  return res;
}
struct{
  int lim;
//   multiset<int> x;
  int sum;
  int dodaj(int w){
    sum += w;
    if(sum > lim){
      w -= sum - lim;
      sum = lim;
//       auto pom = x.end();
//       pom--;
//       sum -= *pom;
//       w -= *pom;
//       x.erase(pom);
    }
    return w;
  }
}wara[MAX],warb[MAX];

#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n >> k >> a >> b >> q;
  R(i,n){
    wara[i].lim = a;
    warb[i].lim = b;
  }
  R(i,q){
    int z;
    cin >> z;
    if(z == 1){
      int d,x;
      cin >> d >> x;
      d--;
      dod(0,d,wara[d].dodaj(x));
      dod(1,d,warb[d].dodaj(x));
    }else{
      int d;cin >> d;
      d--;
      cout << sum(1,d) + sum(0,n) - sum(0,d+k) << "\n";
    }
  }
}