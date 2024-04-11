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

const int MX=55, MOD=1e9+7;
int n;
string gr[MX];
bitset<MX> black[MX];
int aw[MX][MX][MX][MX];
int dp[MX][MX][MX][MX];

bool allWhite(int bx, int by, int ex, int ey) {
	if(aw[bx][by][ex][ey] == -1) {
		bool ans=0;
		if(bx == ex) {
			if(by == ey) {
				ans = !black[bx][by];
			} else {
				ans = allWhite(bx, by, ex, ey-1) && allWhite(bx, ey, ex, ey);
			}
		} else {
			ans = allWhite(bx, by, ex-1, ey) && allWhite(ex, by, ex, ey);
		}
		aw[bx][by][ex][ey] = ans;
	}
	return aw[bx][by][ex][ey];
}
int getAns(int bx, int by, int ex, int ey) {
	if(dp[bx][by][ex][ey] == -1) {
		int ans;
		if(allWhite(bx, by, ex, ey)) ans = 0;
		else						 ans = max(ey-by+1, ex-bx+1);

		// cut hor
		REP(i,bx,ex)
			ans = min(ans, getAns(bx,by,i,ey)+getAns(i+1,by,ex,ey));

		// cut ver
		REP(i,by,ey)
			ans = min(ans, getAns(bx,by,ex,i)+getAns(bx,i+1,ex,ey));

		dp[bx][by][ex][ey] = ans;
	}
	return dp[bx][by][ex][ey];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>gr[i];
    RE(i,n) RE(j,n) black[i][j] = (gr[i][j] == '#');
    RE(i,n) RE(j,n) RE(k,n) RE(l,n) dp[i][j][k][l] = aw[i][j][k][l] = -1;
    cout<<getAns(0,0,n-1,n-1)<<endl;
}