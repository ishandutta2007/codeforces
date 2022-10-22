#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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

const int MX = 2002;
int n, h, l, r;
int a[MX];
int dp[MX][MX];

int getAns(int i, int j);
int getAnsInc(int i, int j) {
	i += h;
	i %= h;
	return getAns(i,j)+((l<=i && i<=r)?1:0);
}
int getAns(int i, int j) {
	if(j == n) return 0;
	if(dp[i][j] == -1) {
		int mx=0;
		mx = max(mx, getAnsInc(i+a[j], j+1));
		mx = max(mx, getAnsInc(i+a[j]-1, j+1));
		dp[i][j] = mx;
	}
	return dp[i][j];
}

void program() {
	cin>>n>>h>>l>>r;
	RE(i,n) cin>>a[i];
	RE(i,MX) RE(j,MX) dp[i][j] = -1;
	cout<<getAns(0,0)<<endl;
}