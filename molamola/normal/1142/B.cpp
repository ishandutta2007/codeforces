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

int n, m, q;
int p[200020], a[200020], ip[200020];
set <int> Sx[200020];

int get_l(int x, int v) {
	auto it = Sx[x].upper_bound(v);
	if(it == Sx[x].begin()) return 0;
	--it; return *it;
}

int nxt[200020][20];
int L[200020];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n;i++) scanf("%d", p+i);
	for(int i=1;i<=n;i++) ip[p[i]] = i;
	for(int i=1;i<=m;i++) scanf("%d", a+i);
	if(n == 1) {
		rep(i, q) printf("1"); puts("");
		return 0;
	}
	for(int i=1;i<=m;i++) Sx[a[i]].insert(i);
	
	for(int i=1;i<=m;i++) {
		int v = ip[a[i]];
		int pre_v = (v == 1 ? n : v-1);
		int g = get_l(p[pre_v], i);
		nxt[i][0] = g;
	}
	for(int i=1;i<20;i++) for(int j=1;j<=m;j++) {
		nxt[j][i] = nxt[ nxt[j][i-1] ][i-1];
	}
	for(int i=1;i<=m;i++) {
		int x = i;
		rep(j, 20) if(1<<j & (n-1)) x = nxt[x][j];
		L[i] = max(L[i-1], x);
	}
	for(int i=1;i<=q;i++) {
		int l, r; scanf("%d%d", &l, &r);
		if(L[r] >= l) printf("1");
		else printf("0");
	}
	puts("");
	return 0;
}