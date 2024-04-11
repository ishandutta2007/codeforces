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

const int MX = 501;
int n, a[MX];
int dp[MX][MX];
int comb[MX][MX];

int getAns(int l, int r) {
	if(r < l) return 0;
	if(dp[l][r] == -1) {
		dp[l][r] = r-l+1;
		int val = a[l];
		if(dp[l][r] == 1) comb[l][r] = val;
		dp[l][r] = min(dp[l][r], 1+getAns(l+1,r));
		int b = l+1;
		REP(e,b,r+1) {
			if(getAns(b,e) == 1 && comb[b][e] == val) {
				b = e+1;
				val++;
				dp[l][r] = min(dp[l][r], 1+getAns(b,r));
				if(b == r+1) comb[l][r] = val;
			}
		}
	}
	return dp[l][r];
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	RE(i,n) RE(j,n) dp[i][j] = -1;
	cout<<getAns(0,n-1)<<endl;
}