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
#define sz size()
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

const int MX = 5e5;
int n, m, k, s[MX][2], f[MX][2];
string ans;

void program() {
	cin>>n>>m>>k;
	RE(i,k) RE(j,2) cin>>s[i][j];
	RE(i,k) RE(j,2) cin>>f[i][j];
	RE(i,n-1) ans.pb('U');
	RE(i,m-1) ans.pb('L');
	bool dir=1;
	RE(i,n) {
		RE(i,m-1) {
			if(dir) ans.pb('R');
			else ans.pb('L');
		}
		dir = !dir;
		if(i != n-1) ans.pb('D');
	}
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
}