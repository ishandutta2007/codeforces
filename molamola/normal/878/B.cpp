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
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, k, m;
int A[100010];

void Merge(vector <pii> &A, vector <pii> B) {
	for(pii e : B) {
		if(szz(A) == 0 || A.back().Fi != e.Fi) A.pb(e);
		else {
			A.back().Se += e.Se;
			if(A.back().Se >= k) A.back().Se -= k;
			if(A.back().Se == 0) A.pop_back();
		}
	}
}

ll get(vector <pii> A) {
	ll res = 0;
	for(pii e : A) res += e.Se;
	return res;
}

void solve() {
	scanf("%d%d%d", &n, &k, &m);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	vector <pii> X;
	for(int i=1;i<=n;i++) {
		if(szz(X) == 0 || X.back().Fi != A[i]) X.push_back(pii(A[i], 1));
		else {
			X.back().Se += 1;
			if(X.back().Se == k) X.pop_back();
		}
	}
	if(m == 1) {
		printf("%lld\n", get(X));
		return;
	}
	vector <pii> Y = X;
	Merge(Y, X);
	if(szz(Y) == 0) {
		if(m & 1) printf("%lld\n", get(X));
		else puts("0");
		return;
	}
	int f = 0;
	for(int i=0;i<szz(X);i++, f++) {
		if(X[i].Fi == X[szz(X)-1-i].Fi) {
			int s = X[i].Se + X[szz(X)-1-i].Se;
			if(s != k) break;
		}
		else break;
	}
	ll ans = 0;
	if(szz(X) == szz(Y) && szz(Y) % 2 == 1 && f >= szz(Y) / 2) {
		f = szz(Y) / 2;
		int temp = X[f].Se * (ll)m % k;
		vector <pii> T;
		rep(i, f) T.pb(X[i]);
		vector <pii> v;
		if(temp > 0) v.pb(pii(X[f].Fi, temp));
		Merge(T, v); v.clear();
		rep(i, f) v.pb(X[szz(X)-f+i]);
		Merge(T, v);
		printf("%lld\n", get(T));
	}
	else {
		ans = (m - 1) * get(Y) - (m - 2) * get(X);
		printf("%lld\n", ans);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case %d: ", tc);
		solve();
	}
	return 0;
}