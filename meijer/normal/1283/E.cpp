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
int n, m=0, x[MX], y[MX];
bool ex[MX];
int dp[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>x[i], x[i]--, ex[x[i]] = 1;
	RE(i,n) if(ex[i]) y[m++] = i;
	sort(x, x+n);
	dp[m] = 0;
	REV(i,0,m) {
		dp[i] = dp[i+1]+1;
		if(i+2 < m && y[i+2]-2 == y[i] && y[i+1]-1 == y[i]) dp[i] = min(dp[i], dp[i+3] + 1);
		if(i+1 < m && (y[i+1]-1 == y[i]) || y[i+1]-2 == y[i]) dp[i] = min(dp[i], dp[i+2] + 1);
	}
	int gr=0;
	RE(i,n) x[i]++;
	RE(i,n+2) ex[i] = 0;
	RE(i,n) {
		RE(j,3) {
			if(ex[x[i]-1+j] == 0) {
				ex[x[i]-1+j] = 1;
				gr++;
				break;
			}
		}
	}
	cout<<dp[0]<<" "<<gr<<endl;
}