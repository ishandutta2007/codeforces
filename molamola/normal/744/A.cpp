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

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int p[1010], z[1010], e[1010];
int Find(int x){
	return p[x] == x ? x : p[x] = Find(p[x]);
}

int n, m, k;
int c[1010];

void solve(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i,k){
		int x; scanf("%d", &x);
		c[i] = x;
	}
	for(int i=1;i<=n;i++)p[i] = i, z[i] = 1;
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		x = Find(x), y = Find(y);
		if(x == y)e[x]++;
		else{
			p[x] = y;
			e[y] += e[x] + 1;
			z[y] += z[x];
		}
	}
	vector <int> v;
	rep(i, k)v.pb(z[Find(c[i])]);
	ll ans = -m;
	sort(all(v));
	int s = 0;
	for(int i=0;i<sz(v)-1;i++)s += v[i];
	v[sz(v)-1] = n - s;
	for(int e : v)ans += e * (e-1) / 2;
	printf("%lld", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}