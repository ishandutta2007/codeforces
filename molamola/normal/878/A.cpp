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

int n;
int p[500050][2];

int Do(int x, int a, int b) {
	if(a == '|') return x | b;
	if(a == '&') return x & b;
	if(a == '^') return x ^ b;
	return 0;
}

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		char ch[3];
		scanf("%s%d", ch, p[i]+1);
		p[i][0] = (ch[0]);
	}
	int ans[3] = {};
	ans[1] = 1023;
	rep(i, 10) {
		int x = 1<<i, y = 0;
		for(int i=1;i<=n;i++) {
			x = Do(x, p[i][0], p[i][1]);
			y = Do(y, p[i][0], p[i][1]);
		}
		int a = !!(x & 1<<i);
		int b = !!(y & 1<<i);
		if(a == 1 && b == 0);
		else if(a == 1 && b == 1) ans[0] |= 1<<i;
		else if(a == 0 && b == 0) ans[1] ^= 1<<i;
		else ans[2] |= 1<<i;
	}
	printf("3\n");
	rep(u, 3) {
		printf("%c %d\n", "|&^"[u], ans[u]);
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