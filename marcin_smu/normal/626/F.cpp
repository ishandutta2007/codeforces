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

#define MAX 1001
int n,k;
int t[MAX];
int dp[2][MAX][MAX];
const int P = 1e9 + 7;
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n >> k;
  R(i,n){
    cin >> t[i];
  }
  sort(t,t+n);
  dp[1][0][0] = 1;
  dp[1][1][0] = 1;
  F(ii,1,n){
    int roz = t[ii] - t[ii-1];
    int i = ii&1;
    R(j,n)R(kk,k+1){
      dp[!i][j][kk] = 0;
    }
    R(j,n)R(kk,k+1){
      dp[i][j][kk] %= P;
      if(kk + j * roz <= k){
        dp[!i][j][kk + j * roz] += dp[i][j][kk] * (j + 1) % P;
        dp[!i][j+1][kk + j * roz] += dp[i][j][kk];
        if(j)
          dp[!i][j-1][kk + j * roz] += dp[i][j][kk] * j % P;
      }
    }
  }
  int res = 0;
  R(i,k+1){
    res += dp[n&1][0][i] % P;
  }
  cout << res % P << endl;
}