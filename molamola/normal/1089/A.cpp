#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int d[6][6][210][210];
pii pre[6][6][210][210];

int main() {
	d[0][0][0][0] = 1;
	for(int i=1;i<=5;i++) {
		int X = (i < 5 ? 25 : 15);
		vector <pii> L[2];
		for(int a=0;a<=X-2;a++) L[1].pb(pii(X, a));
		for(int a=X+1;a<=200;a++) L[1].pb(pii(a, a-2));
		for(int a=0;a<=X-2;a++) L[0].pb(pii(a, X));
		for(int a=X+1;a<=200;a++) L[0].pb(pii(a-2, a));
		rep(a, 3) rep(j, 201) rep(k, 201) if(d[i-1][a][j][k] && i-1-a < 3) {
			rep(v, 2) for(pii e : L[v]) {
				if(j+e.Fi <= 200 && k+e.Se <= 200) {
					d[i][a+v][j+e.Fi][k+e.Se] = 1;
					pre[i][a+v][j+e.Fi][k+e.Se] = e;
				}
			}
		}
	}
	int tc; scanf("%d", &tc);
	rep(tt, tc) {
		int a, b; scanf("%d%d", &a, &b);
		int ax = -1, bx = -1, c = -11234;
		for(int i=3;i<=5;i++) {
			for(int j : {3, i-3}) {
				if(d[i][j][a][b]) {
					int t = j - (i - j);
					if(c < t) c = t, ax = i, bx = j;
				}
			}
		}
		if(ax == -1) puts("Impossible");
		else {
			printf("%d:%d\n", bx, ax - bx);
			vector <pii> ans;
			while(ax > 0) {
				pii p = pre[ax][bx][a][b];
				if(p.Fi > p.Se) --bx;
				--ax;
				ans.pb(p);
				a -= p.Fi; b -= p.Se;
			}
			reverse(all(ans));
			for(pii e : ans) printf("%d:%d ", e.Fi, e.Se); puts("");
		}
	}
	return 0;
}