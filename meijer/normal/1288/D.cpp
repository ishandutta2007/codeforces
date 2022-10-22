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

const int MX = 5e5;
int n, m, a[MX][8];
int A[MX];
int dp[256];
int u=1, v=1;

bool possible(int f) {
	RE(i,n) {
		A[i] = 0;
		RE(j,m)
			if(a[i][j] >= f)
				A[i] |= (1<<j);
	}
	RE(i,256) dp[i] = 0;
	dp[0] = 1;
	RE(i,n) {
		if(dp[A[i]] == 0) {
			int cur = A[i];
			while(cur) {
				dp[cur] = i+1;
				cur = (cur-1)&A[i]; 
			}
		}
	}
	RE(i,n) {
		int inv = (~A[i])&((1<<m)-1);
		if(dp[inv]) {
			u=i+1;
			v=dp[inv];
			return 1;
		}
	}
	return 0;
}

void program() {
	cin>>n>>m;
	RE(i,n) RE(j,m) cin>>a[i][j];
	int lb=0, ub=1e9;
	while(lb != ub) {
		int mid=(lb+ub+1)/2;
		if(possible(mid)) lb = mid;
		else ub = mid-1;
	}
	possible(lb);
	cout<<u<<" "<<v<<endl;
}