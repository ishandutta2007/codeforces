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

const int MX=1e5+1e4, MOD=1e9+7;
int n, m, X[99], S[99], x[99], s[99], SA[99];
int dp[99][MX];
int minimal[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,n) cin>>X[i]>>S[i];
    RE(i,n) SA[i] = i;
    sort(SA, SA+n, [](int i, int j) {
    	return X[i] < X[j];
    });
    RE(i,n) x[i] = X[SA[i]], s[i] = S[SA[i]];
    REP(i,0,n) {
    	// dp[i][j] is the minimum number of coins to cover [1;j] with antennas [0;i]
    	dp[i][0] = 0;
    	REP(j,1,m+1) {
    		if(i == 0) {
    			// you have to cover the area [1;j] with only antenna 0
    			dp[i][j] = max(0,max(x[i]-1-s[i], j-x[i]-s[i]));
    		} else {
    			dp[i][j] = dp[i-1][j];
    			dp[i][j] = min(dp[i][j], dp[i-1][0] + max(0,max(x[i]-1-s[i], j-x[i]-s[i])));

    			int r = 2*x[i]-j;
    			if(min(r, x[i]-s[i]) > 0)
    				dp[i][j] = min(dp[i][j], minimal[min(r, x[i]-s[i])-1] + x[i]-s[i]-1);
    		}
    	}
    	RE(j,m+1) {
    		minimal[j] = dp[i][j] - j;
    		if(j != 0)
    			minimal[j] = min(minimal[j], minimal[j-1]);
    	}
    }
    cout<<dp[n-1][m]<<endl;
}