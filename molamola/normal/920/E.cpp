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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<ll, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<ldouble, ldouble> pdd;

int n, m;
set <pii> S;
int L[4040][4040];
int p[200020]; int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
int z[200020];
int deg[200020];

void Uni(int x, int y) {
	int pi = Find(x), pj = Find(y);
	if(pi != pj) p[pi] = pj, z[pj] += z[pi];
}

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int x, y; scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		if(n <= 4000) L[x][y] = 1;
		S.insert(pii(x, y));
		deg[x]--; deg[y]--;
	}
	for(int i=1;i<=n;i++) p[i] = i, z[i] = 1, deg[i] += n-1;
	if(n <= 4000) {
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(L[i][j] == 0) {
			Uni(i, j);
		}
	}
	else {
		vector <int> o, u;
		for(int i=1;i<=n;i++) {
			if(deg[i] > 70) o.pb(i);
			else u.pb(i);
		}
		for(int i=1;i<szz(o);i++) {
			Uni(o[0], o[i]);
		}
		for(int e : u) {
			for(int i=1;i<=n;i++) {
				if(S.find(pii(min(e, i), max(e, i))) == S.end()) {
					Uni(e, i);
				}
			}
		}
	}
	vector <int> v;
	for(int i=1;i<=n;i++) if(p[i] == i) v.pb(z[i]);
	sort(all(v));
	printf("%d\n", szz(v));
	for(int e : v) printf("%d ", e); puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}