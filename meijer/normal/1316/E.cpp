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

const int MX = 2e5, BIT=130;
ll n, p, k, a[MX], s[MX][7], SA[MX];
ll dp[MX][BIT];
ll notAudience;

int countBits(int x) {
	int cnt=0;
	RE(i,p) if(x&(1<<i)) cnt++;
	return cnt;
}
ll getAns(int i, int j) {
	if(i == -1) {
		if(j == ((1<<p)-1)) return 0;
		else return -1e18;
	}
	if(dp[i][j] == -1) {
		int bits = countBits(j);
		int remAudience = i+1-p+bits-notAudience;
		ll ans = -1e18;
		RE(I,p) if((j&(1<<I)) == 0) {
			ans = max(ans, s[SA[i]][I]+getAns(i-1, j|(1<<I)));
		}
		ans = max(ans, (remAudience <= 0 ? 0 : a[SA[i]])+getAns(i-1,j));
		dp[i][j] = ans;
	}
	return dp[i][j];
}

void program() {
	cin>>n>>p>>k;
	notAudience = n-p-k;
	RE(i,n) cin>>a[i];
	RE(i,n) RE(j,p) cin>>s[i][j];
	RE(i,n) SA[i] = i;
	sort(SA, SA+n, [](int i, int j) {
		return a[i]<a[j];
	});
	RE(i,n) RE(j,BIT) dp[i][j] = -1;
	cout<<getAns(n-1, 0)<<endl;
}