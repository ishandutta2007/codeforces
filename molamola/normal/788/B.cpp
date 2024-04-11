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

int p[1000010];
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]) ;}

int deg[1000010], chk[1000010];

void solve(){
	int n, m; scanf("%d%d", &n, &m);
	if(m < 2){
		puts("0");
		return;
	}
	for(int i=1;i<=n;i++)p[i] = i;
	int cc = 0;
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		p[Find(x)] = Find(y);
		cc += (x == y);
		if(x != y)deg[x]++, deg[y]++;
		chk[x] = chk[y] = 1;
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)if(Find(i) == i && chk[i] > 0)++cnt;
	if(cnt != 1){
		puts("0");
		return;
	}
	ll ans = (ll)cc * (cc - 1) / 2;
	ans += (ll)cc * (m - cc);
	for(int i=1;i<=n;i++)ans += (ll)deg[i] * (deg[i] - 1) / 2;
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}