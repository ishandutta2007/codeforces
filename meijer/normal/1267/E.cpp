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
 
const ll MX=105, MOD=1e9+7;

int n, m;
int a[MX][MX];
int dp[MX][MX];
vi ans;
int C;

void fillAns(int i, int j) {
  if(i == 0) {
    if(j != 0 && dp[i][j] == 0) {
      ans.pb(i+1);
    }
  } else {
    if(dp[i][j] == dp[i-1][j] + a[i][C] - a[i][n-1]) {
      fillAns(i-1, j);
    } else {
      fillAns(i-1, j-1);
      ans.pb(i+1);
    }
  }
}
bool isPossible(int x) {
  RE(c,n-1) {
    RE(i,m) RE(j,x+1) {
      if(i == 0) {
        dp[i][j] = a[i][c] - a[i][n-1];
        if(j != 0)
          dp[i][j] = max(dp[i][j], 0);
      } else {
        dp[i][j] = dp[i-1][j] + a[i][c] - a[i][n-1];
        if(j != 0)
          dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
      }
    }
    if(dp[m-1][x] >= 0) {
      C = c;
      ans.clear();
      fillAns(m-1,x);
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>m;
  RE(i,m) RE(j,n) cin>>a[i][j];
  int lb=0, ub=m;
  while(lb != ub) {
    int mid=(lb+ub)/2;
    if(isPossible(mid)) ub = mid;
    else lb = mid+1;
  }
  isPossible(lb);
  cout<<lb<<endl;
  RE(i,lb) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
}