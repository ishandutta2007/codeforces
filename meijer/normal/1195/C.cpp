#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=2e5, MOD=1e9+7;
ll n, h[MX][2], dp[MX][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>h[i][0];
    RE(i,n) cin>>h[i][1];
    REV(i,0,n) {
    	if(i == n-1) {
    		dp[i][0] = h[i][0];
    		dp[i][1] = h[i][1];
    	} else {
    		dp[i][0] = max(dp[i+1][0], h[i][0]+dp[i+1][1]);
    		dp[i][1] = max(dp[i+1][1], h[i][1]+dp[i+1][0]);
    	}
    }
    cout<<max(dp[0][0], dp[0][1])<<endl;
}