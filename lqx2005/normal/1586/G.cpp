#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef double db; 
const int N = 4e5 + 10, P = 1e9 + 7;
int n;
int a[N], b[N];
int suf[N];
int dp[N], t[N], vis[N], mx[N];

void add(int x, int v) {
	for(int i = x; i <= n * 2; i += i & -i) (t[i] += v) %= P;
	return;
}

int sum(int x) {
	int res = 0;
	for(int i = x; i > 0; i -= i & -i) (res += t[i]) %= P;
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		suf[a[i]] = b[i];
	}
	for(int i = n * 2; i >= 1; i--) {
		if(suf[i]) {
			dp[i] = (sum(suf[i]) + 1) % P;
			add(suf[i], dp[i]);
		}
	}
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int x;
		scanf("%d", &x);
		vis[a[x]] = 1;
		mx[a[x]] = max(mx[a[x]], b[x]);
	}
	for(int i = n * 2; i >= 1; i--) mx[i] = max(mx[i + 1], mx[i]);
	int ans = 0;
	for(int i = 1; i <= n * 2; i++) {
		if(suf[i]) {
			if(vis[i] || suf[i] < mx[i + 1]) (ans += dp[i]) %= P;
		}
	}
	printf("%d\n", ans);
	return 0;
}