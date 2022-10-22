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

const int MX = 3000;
int n, m;
int a[MX], b[MX], c[MX];

bool possible(int x) {
	RE(i,n) c[i] = (a[i]+x)%m;
	sort(c,c+n);
	RE(i,n) if(b[i] != c[i]) return 0;
	return 1;
}

void program() {
	cin>>n>>m;
	RE(i,n) cin>>a[i];
	RE(i,n) cin>>b[i];
	sort(a, a+n);
	sort(b, b+n);
	int mn=INF;
	RE(i,n) {
		if(possible((b[0]-a[i]+m)%m))
			mn = min(mn, (b[0]-a[i]+m)%m);
	}
	cout<<mn<<endl;
}