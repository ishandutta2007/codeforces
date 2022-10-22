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
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e15
#define pb push_back
#define fi first
#define se second

const int MX=3e5, MOD=1e9+7;
int n, a[MX], b, lg;
ll dp[19][MX];

ll getAns(int i, int bg) {
	if(i == lg) return 0;
	if(bg >= n-1) return INF;
	if(dp[i][bg] == -1) {
		ll ans = getAns(i,bg+1);
		ll minBg = (1<<(i+1))-2;
		if(bg >= minBg)
			ans = min(ans, a[bg]+getAns(i+1,bg+1));
		dp[i][bg] = ans;
	}
	return dp[i][bg];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    lg = 0; while((1<<lg) < n) lg++;
    RE(i,n) cin>>a[i];
    RE(i,n) if(a[i] == -1) b = i;
    RE(i,b) a[i] = 0;
    REP(i,b,n) a[i] = a[i+1];
    RE(i,19) RE(j,MX) dp[i][j] = -1;
    cout<<getAns(0,0)<<endl;
}