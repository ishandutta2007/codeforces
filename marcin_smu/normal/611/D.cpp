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
#define MAX 5101
int n;
string z;
int dp[MAX][MAX];
bool cz[MAX][MAX];
int kmr[MAX*20][20];
int P2[MAX];
const int P = 1e9 + 7;
bool cmp(int p1,int p2,int dl){
  int k = P2[dl];
  debug(p1,p2,dl,k);
  PII a = {kmr[p1][k], kmr[p1+dl-(1<<k)][k]};
  PII b = {kmr[p2][k], kmr[p2+dl-(1<<k)][k]};
  debug(a.FI,b.FI);
  return a < b;
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n >> z;
  R(i,n)
    kmr[i][0] = z[i];
  F(j,1,15){
    vector<PII> pom;
    R(i,n)
      pom.PB(MP(kmr[i][j-1]*1000000+kmr[i+(1<<(j-1))][j-1],i));
    sort(ALL(pom));
    int ak = -1;
    R(i,n){
      if(!i || pom[i].FI != pom[i-1].FI)ak++;
      kmr[pom[i].SE][j] = ak;
    }
  }
  P2[1] = 0;
  F(i,2,n+1)P2[i] = P2[i/2] + 1;
  
  dp[0][0] = 1;
  F(i,1,n+1){
    R(j,i){
      dp[i][j] = dp[i-1][j];
      int dl = i-j;
      if(dl*2 <= i && z[i-dl]!='0'){
        if(cmp(i-2*dl,i-dl,dl)){
          debug("mam",i,j);
          dp[i][j] += dp[i-dl][j-dl];
        }else
          cz[i][j] = 1;
      }
      if(cz[i-1][j])
        dp[i][j] += dp[j][j-dl+1];
      dp[i][j] %= P;
      debug(i,j,dp[i][j],cz[i][j]);
    }
  }
  int res = 0;
  R(i,n+1)res += dp[n][i];
  cout << res % P << endl;
}