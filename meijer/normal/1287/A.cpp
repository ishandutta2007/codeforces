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
 
const int MX=500, MOD=1e9+7;
int t, k, dp[MX];
char s[MX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--) {
    cin>>k;
    RE(i,k) cin>>s[i];
    dp[k] = 0;
    REV(i,0,k) dp[i] = (s[i] == 'A' ? 0 : dp[i+1]+1);
    int ans = 0;
    RE(i,k) if(s[i] == 'A') ans = max(ans, dp[i+1]);
    cout<<ans<<endl;
  }
}