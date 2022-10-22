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

const int MX = 1e6+1;
int n, m, p, a[MX], b[MX];
mt19937 rng(time(NULL));

void program() {
	cin>>n>>m>>p;
	RE(i,n) cin>>a[i];
	RE(i,m) cin>>b[i];

	int ans=0;
	RE(i,n) {
		if(a[i] % p != 0) break;
		ans++;
	}
	RE(i,m) {
		if(b[i] % p != 0) break;
		ans++;
	}
	cout<<ans<<endl;
}