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
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int n, m, k;
int B[100010];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++) {
		scanf("%d", B + i);
	}
	vector <int> w;
	for(int i=2;i<=n;i++) w.pb(B[i] - B[i-1] - 1);
	ll ans = n;
	sort(all(w));
	rep(i, n - k) ans += w[i];
	printf("%lld\n", ans);
	return 0;
}