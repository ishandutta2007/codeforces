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
#include <time.h>
#include <limits.h>

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

int N;

int get_dp(int u, int x, int y) {
	if(x == 0 || y == 0) return -12345;
	if(x == 1 && y == 1) return 0;
	if(x > y) swap(x, y);
	if(u == 0) {
		int c = 0;
		if(x == 1 && y % 4 == 0) ++c;
		return c + (x + y) / 2;
	}
	else {
		int r = (x-1) / 2 + (y-1) / 2 + 1;
		int c = (x == 1 && y % 4 == 0) || (x > 1 && (x + y) % 4 == 2);
		return r ^ c;
	}
}

int can(int u, int i, int j, int a, int b) {
	int ta = (b ? u : (a & 1));
	int tb = (a ? 0 : (b & 1) ^ u);
	int xu = (ta != tb);
	int diff = ((a+b)&1) ^ u;
	int xi = (i-a) + b; if(b && (i-a) && diff) --xi;
	int xj = (j-b) + a; if(a && (j-b) && diff) --xj;
	return get_dp(xu, xi, xj) + 1 == get_dp(u, i, j);
}

int main() {
	
	char S[200020], T[200020];
	vector <pii> vs, vt;
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	for(int i=1, p=1;S[i];i++) {
		if(!S[i+1] || S[i] != S[i+1]) { vs.pb(pii(S[i]-'a', i-p+1)); p = i + 1; }
	}
	for(int i=1, p=1;T[i];i++) {
		if(!T[i+1] || T[i] != T[i+1]) { vt.pb(pii(T[i]-'a', i-p+1)); p = i + 1; }
	}
	reverse(all(vs)); reverse(all(vt));
	vector <pii> ans;
	while(szz(vs) != 1 || szz(vt) != 1) {
		int ls = szz(vs), lt = szz(vt);
		int u = (vs.back().Fi != vt.back().Fi);
		int fa = -1, fb = -1;
		for(int a=0;a<5 && a<=ls;a++) if(fa == -1) for(int b=0;b<5 && b<=lt;b++) {
			if(can(u, ls, lt, a, b)) {
				fa = a; fb = b; break;
			}
		}
		vector <pii> t[2];
		int la = 0, lb = 0;
		for(int i=ls-fa;i<ls;i++) t[0].pb(vs[i]), la += vs[i].Se;
		for(int i=lt-fb;i<lt;i++) t[1].pb(vt[i]), lb += vt[i].Se;
		rep(i, fa) vs.pop_back();
		rep(i, fb) vt.pop_back();
		for(pii e : t[1]) {
			if(szz(vs) && vs.back().Fi == e.Fi) vs.back().Se += e.Se;
			else vs.pb(e);
		}
		for(pii e : t[0]) {
			if(szz(vt) && vt.back().Fi == e.Fi) vt.back().Se += e.Se;
			else vt.pb(e);
		}
		ans.pb(pii(la, lb));
	}
	printf("%d\n", szz(ans));
	for(pii e : ans) printf("%d %d\n", e.Fi, e.Se);
	return 0;
}