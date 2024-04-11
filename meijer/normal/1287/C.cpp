#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const int MX=110, MOD=1e9+7;
int n, p[MX];
set<int> remaining;
int dp[MX][MX][MX][2];

int getDP(int i, int j, int k, bool m) {
  if(j < 0) return INF;
  if(k < 0) return INF;
  if(i == n) return 0;
  if(dp[i][j][k][m] == -1) {
    if(i == 0) {
      if(p[i] == 0)
        dp[i][j][k][m] = min(getDP(i+1,j-1,k,0), getDP(i+1,j,k-1,1));
      else
        dp[i][j][k][m] = getDP(i+1,j,k,p[i]%2);
    } else {
      dp[i][j][k][m] = 0;
      if(p[i] == 0) {
        if(m) dp[i][j][k][m] = min(1+getDP(i+1,j-1,k,0),   getDP(i+1,j,k-1,1));
        else  dp[i][j][k][m] = min(  getDP(i+1,j-1,k,0), 1+getDP(i+1,j,k-1,1));
      } else  dp[i][j][k][m] = getDP(i+1,j,k,p[i]%2) + (m != p[i]%2);
    }
  }
  return dp[i][j][k][m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  RE(i,n) cin>>p[i];
  RE(i,n) remaining.insert(i+1);
  RE(i,n) if(p[i]) remaining.erase(p[i]);
  int e=0, u=0;
  for(int v:remaining) {
    if(v%2) u++;
    else e++;
  }
  RE(i,MX) RE(j,MX) RE(k,MX) dp[i][j][k][0] = dp[i][j][k][1] = -1;
  cout<<getDP(0,e,u,0)<<endl;
}