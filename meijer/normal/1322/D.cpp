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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5002;
int n, m;
int l[MX], s[MX], c[MX];
int dp[MX][MX];

void update(int x, int y) {
	if(x >= MX) return;
	int newVal = dp[x][y]+(y/2)*c[x+1];
	if(newVal > dp[x+1][y/2]) {
		dp[x+1][y/2] = newVal;
		update(x+1, y/2);
	}
}

void program() {
	cin>>n>>m;
	RE(i,n) cin>>l[i];
	RE(i,n) cin>>s[i];
	RE(i,n+m) cin>>c[i+1];
	RE(i,MX) RE(j,MX) dp[i][j] = -INF;
	RE(i,MX) dp[i][0] = 0;
	REV(i,0,n) {
		REV(j,0,n+m+1) {
			if(dp[l[i]][j] == -INF) continue;
			dp[l[i]][j+1] = max(dp[l[i]][j+1], dp[l[i]][j]-s[i]+c[l[i]]);
			update(l[i], j+1);
		}
	}
	cout<<dp[n+m+1][0]<<endl;
}