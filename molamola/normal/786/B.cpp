#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int n, q, s;

const int ADD = 1<<17;
vector <pii> E[550000];
const int SH = ADD * 2;

ll dis[550000];
int chk[550000];

void solve(){
	scanf("%d%d%d", &n, &q, &s);
	for(int i=ADD*2-1;i>1;i--){
		int u = i / 2;
		E[i].pb(pii(0, u));
		E[SH+u].pb(pii(0, SH+i));
	}
	for(int i=0;i<ADD;i++){
		int u = ADD + i;
		int v = ADD + SH + i;
		E[u].pb(pii(0, v));
		E[v].pb(pii(0, u));
	}
	rep(i, q){
		int c; scanf("%d", &c);
		if(c == 1){
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			E[ADD + x].pb(pii(z, ADD + y));
		}
		else if(c == 2){
			int v, l, r, z; scanf("%d%d%d%d", &v, &l, &r, &z);
			l += ADD; r += ADD;
			while(l <= r){
				if(l & 1)E[ADD + v].pb(pii(z, l + SH));
				if(!(r&1))E[ADD + v].pb(pii(z, r + SH));
				l = (l + 1) >> 1;
				r = (r - 1) >> 1;
			}
		}
		else{
			int v, l, r, z; scanf("%d%d%d%d", &v, &l, &r, &z);
			l += ADD; r += ADD;
			while(l <= r){
				if(l & 1)E[l].pb(pii(z, ADD + v));
				if(!(r&1))E[r].pb(pii(z, ADD + v));
				l = (l + 1) >> 1;
				r = (r - 1) >> 1;
			}
		}
	}
	priority_queue <pll, vector<pll>, greater<pll> > pq;
	for(int i=0;i<1<<19;i++)dis[i] = 1e18;
	dis[ADD + s] = 0; pq.push(pll(0, ADD + s));
	while(!pq.empty()){
		pll t = pq.top(); pq.pop();
		if(chk[t.Se] == 1)continue;
		chk[t.Se] = 1;
		for(auto &e : E[t.Se]){
			if(dis[e.Se] > e.Fi + t.Fi){
				dis[e.Se] = e.Fi + t.Fi;
				pq.push(pll(dis[e.Se], e.Se));
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[ADD + i] > 1e17)printf("-1 ");
		else printf("%lld ", dis[ADD + i]);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}