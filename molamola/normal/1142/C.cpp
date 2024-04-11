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
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

pll operator-(pll a, pll b) { return pll(a.Fi - b.Fi, a.Se - b.Se); }
ll operator/(pll a, pll b) { return a.Fi * b.Se - a.Se * b.Fi; }

int n;
pll p[200020];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		ll x, y; scanf("%lld%lld", &x, &y);
		y -= x * x;
		p[i] = pll(x, y);
	}
	sort(p+1, p+1+n);
	vector <pll> np, cvx;
	for(int i=1;i<=n;i++) {
		if(i == n || p[i].Fi != p[i+1].Fi) np.pb(p[i]);
	}
	for(pll e : np) {
		while(szz(cvx) > 1 && (cvx.back() - cvx[szz(cvx)-2]) / (e - cvx.back()) >= 0) cvx.pop_back();
		cvx.pb(e);
	}
	printf("%d\n", szz(cvx) - 1);
	return 0;
}