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

const int MX = 2e5;
int n, a[MX];
int l[MX], r[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];

	l[0] = a[0];
	REP(i,1,n) l[i] = l[i-1]|a[i];

	r[n] = 0;
	REV(i,0,n) r[i] = r[i+1]|a[i];

	int mx=0, best=0;
	RE(i,n) {
		int ans = a[i];
		if(i != 0) ans = (ans|l[i-1]) - l[i-1];
		ans = (ans|r[i+1]) - r[i+1];
		if(ans > mx) mx=ans, best=i;
	}

	cout<<a[best];
	RE(i,n) if(i != best) cout<<" "<<a[i];
	cout<<endl;
}