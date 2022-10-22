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
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, m, k, a[MX], b[MX];

ll getWays(int A, int B) {
	int cnt=0;
	ll aWays=0, bWays=0;
	RE(i,n) {
		if(a[i]) {
			cnt++;
			if(cnt >= A) aWays++;
		} else cnt=0;
	}
	cnt = 0;
	RE(i,m) {
		if(b[i]) {
			cnt++;
			if(cnt >= B) bWays++;
		} else cnt=0;
	}
	return aWays*bWays;
}

void program() {
	cin>>n>>m>>k;
	RE(i,n) cin>>a[i];
	RE(i,m) cin>>b[i];
	ll ans=0;
	for(int i=1; i*i<=k; i++) {
		if(k%i != 0) continue;
		if(i*i == k) {
			ans += getWays(i,i);
		} else {
			ans += getWays(i,k/i);
			ans += getWays(k/i,i);
		}
	}
	cout<<ans<<endl;
}