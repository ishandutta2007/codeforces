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

const int MX = 5e5+1;
int t, n, m, N=0;
ll c[MX];
int id[MX];
int idBack[MX];
map<int, ll> sm;

ll gcd(ll a, ll b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void program() {
	cin>>t;
	while(t--) {
		cin>>n>>m;
		while(N < n) id[N++] = rng();
		RE(i,n) cin>>c[i];
		RE(i,n) idBack[i] = 0;
		RE(i,m) {
			int u, v; cin>>u>>v; u--; v--;
			idBack[v] ^= id[u];
		}
		sm.clear();
		RE(u,n) {
			if(idBack[u] == 0) continue;
			sm[idBack[u]] += c[u];
		}
		ll ans=0;
		for(const pair<int,ll>& p : sm) {
			ans = gcd(p.se, ans);
		}
		printf("%lld\n", ans);
	}
}