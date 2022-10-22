#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
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

const int MX = 64;
ll xo, yo, ax, ay, bx, by, xs, ys, t;
vii points;

ll dist(ii a, ii b) {
	return max(a.fi-b.fi, b.fi-a.fi) + max(a.se-b.se, b.se-a.se);
}
ll getAns(ll b, ll e) {
	ll d = dist(ii{xs, ys}, points[e]) + dist(points[e], points[b]);
	if(d > t) return 0;
	ll ans = e-b+1;
	ii cur = points[b];
	REP(i,e+1,points.size()) {
		d += dist(cur, points[i]);
		if(d > t) return ans;
		ans++; 
		cur = points[i];
	}
	return ans;
}

void program() {
	cin>>xo>>yo>>ax>>ay>>bx>>by>>xs>>ys>>t;
	while(xo <= (ll)2e16 && yo <= (ll)2e16) {
		points.pb(ii{xo, yo});
		xo = xo*ax + bx;
		yo = yo*ay + by;
	}
	ll ans = 0;
	RE(i,points.size()) {
		REP(j,i,points.size()) {
			ans = max(ans, getAns(i,j));
		}
	}
	cout<<ans<<endl;
}