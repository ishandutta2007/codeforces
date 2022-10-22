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
int n, a[MX];
int root;
bitset<MX> used;
vii ans;

void program() {
	cin>>n;
	RE(i,n-1) cin>>a[i];
	root = a[0];
	used.reset();
	used[root] = 1;
	int m=n;
	int e=0;
	while(1) {
		while(used[m]) m--;
		if(m == 0) break;
		used[m] = 1;
		int b=e;
		REP(i,b+1,n-1) {
			if(used[a[i]]) {
				e = i;
				break;
			}
			used[a[i]] = 1;
		}
		if(b == e) e = n-1;
		REP(i,b,e-1) ans.pb({a[i], a[i+1]});
		ans.pb({a[e-1], m});
	}
	cout<<root<<endl;
	RE(i,n-1) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
}