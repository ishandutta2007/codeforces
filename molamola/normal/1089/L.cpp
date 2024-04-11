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

int n, k;
int a[100010], b[100010];
vector <int> X[100010];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", a+i);
	for(int i=1;i<=n;i++) scanf("%d", b+i);
	for(int i=1;i<=n;i++) {
		X[a[i]].pb(b[i]);
	}
	for(int i=1;i<=k;i++) sort(all(X[i]));
	vector <int> w;
	int c = 0;
	for(int i=1;i<=k;i++) {
		if(szz(X[i]) == 0) ++c;
		else {
			for(int j=0;j<szz(X[i])-1;j++) w.pb(X[i][j]);
		}
	}
	sort(all(w));
	ll ans = 0;
	rep(j,c) ans += w[j];
	printf("%lld\n", ans);
	return 0;
}