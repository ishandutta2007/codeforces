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
	cout.tie(NULL);
	program();
}
 
 
//===================//
//   begin program   //
//===================//
 
const int MX = 2e5;
int n, m, k, p[MX], v[MX], d[MX], w[MX];
map<int, ll> dp[MX];

void addMap(map<int, ll>& mp, int i, int x) {
	mp[i] += x;
	auto it = mp.upper_bound(i);
	while(x && it != mp.end()) {
		if(x >= it->se) {
			x -= it->se;
			it++;
			mp.erase(prev(it));
		} else {
			it->se -= x;
			x = 0;
		}
	}
}
void combine(map<int, ll>& a, map<int, ll>& b) {
	if(a.size() < b.size()) swap(a,b);
	for(auto it:b) a[it.fi] += it.se;
}

void program() {
	cin>>n>>m>>k;
	REP(i,1,n) cin>>p[i], p[i]--;
	RE(i,m) {
		int V, D, W;
		cin>>V>>D>>W; D--; V--;
		d[V] = D;
		w[V] = W;
	}
	REV(i,1,n) {
		if(w[i]) addMap(dp[i], d[i], w[i]);
		combine(dp[p[i]], dp[i]);
	}
	ll ans=0;
	for(auto it:dp[0]) ans+=it.se;
	cout<<ans<<endl;
}