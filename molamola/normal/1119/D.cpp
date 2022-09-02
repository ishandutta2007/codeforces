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

int N;
ll A[100010];
pll p[100010];
ll ans[100010];

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%lld", A + i);
	sort(A+1, A+1+N);
	vector <ll> V;
	for(int i=1;i<=N;i++) {
		ll v = A[i+1] - A[i];
		if(i == N) v = 2e18;
		V.pb(v);
	}
	sort(all(V));
	int q; scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		ll l, r; scanf("%lld%lld", &l, &r);
		p[i] = pll(r-l+1, i);
	}
	sort(p+1, p+1+q);
	ll pv = 0, res = 0;
	for(int i=1, j=0;i<=q;i++) {
		while(j < szz(V) && V[j] <= p[i].Fi) {
			res += (V[j] - pv) * (N - j);
			pv = V[j];
			++j;
		}
		ll r = res + (p[i].Fi - pv) * (N - j);
		ans[p[i].Se] = r;
	}
	for(int i=1;i<=q;i++) printf("%lld ", ans[i]); puts("");
	return 0;
}