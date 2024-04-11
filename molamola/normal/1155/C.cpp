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

int n, m;
ll X[300030], P[300030];

ll gc(ll x, ll y) { return y == 0 ? x : gc(y, x%y); }
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%lld", X + i);
	ll g = 0;
	for(int i=2;i<=n;i++) g = gc(g, X[i] - X[i-1]);
	for(int i=1;i<=m;i++) scanf("%lld", P + i);
	for(int i=1;i<=m;i++) if(g % P[i] == 0) {
		printf("YES\n%lld %d\n", X[1], i);
		return 0;
	}
	puts("NO");
	return 0;
}