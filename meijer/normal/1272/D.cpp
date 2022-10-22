#include <bits/stdc++.h>
using namespace std;

//macros
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
#define INF 1e9
#define pb push_back
#define fi first
#define se second

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 1e6;
int n, m;
int a[MX], dp[MX], dp2[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	int ans=1;
	dp[n-1] = 1;
	REV(i,0,n-1) {
		if(a[i] < a[i+1]) dp[i] = dp[i+1]+1;
		else dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	dp2[0] = 1;
	REP(i,1,n) {
		if(a[i] > a[i-1]) dp2[i] = dp2[i-1]+1;
		else dp2[i] = 1;
	}
	REP(i,1,n-1) {
		if(a[i-1] < a[i+1]) {
			ans = max(ans, dp2[i-1]+dp[i+1]);
		}
	}
	cout<<ans<<endl;
}