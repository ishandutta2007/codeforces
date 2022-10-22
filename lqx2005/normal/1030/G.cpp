#pragma GCC optimize("3", "inline", "Ofast")
#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair
#define PI pair<int, int>
typedef long long i64;
typedef unsigned long long u64;
typedef vector<u64> DP;
const int N = 2e6 + 10, P = 1e9 + 7;
int n, p[N], tot = 0, vis[N];
int a[N], cnt[N], zero = 0;
int ans[N];
vector<PI> d[N];
int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

void sieve(int n) {
	vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, d[i].push_back({i, 1});
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) {
				d[i * p[j]] = d[i];
				d[i * p[j]].back().y++;
				break;
			}
			d[i * p[j]] = d[i];
			d[i * p[j]].push_back({p[j], 1});
		}
	}
	return;
}

int insert(int x) {
	int f = 0;
	for(PI &p : d[x]) {
		if(ans[p.x] < p.y) {
			f = 1;
			ans[p.x] = p.y;
		}
	}
	return f;
}

void add(int x) {
	for(PI &p : d[x]) {
		if(ans[p.x] == p.y) {
			cnt[p.x]++;
		}
	}
	return;
}

int check(int x) {
	for(PI &p : d[x]) {
		if(ans[p.x] == p.y && cnt[p.x] <= 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	sieve(N - 10);
	int m = N - 10;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, greater<int> ());
	int pre = -1;
	for(int i = 1; i <= n; i++) {
		if(a[i] == pre) {
			a[i] = pre - 1;
		} else {
			pre = a[i];
			if(!insert(a[i])) a[i] = pre - 1;
		}
		insert(a[i]);
	}
	for(int i = 1; i <= n; i++) add(a[i]);
	for(int i = 1; i <= n; i++) zero |= check(a[i]);
	int prod = 1;
	for(int i = 1; i <= m; i++) if(ans[i]) prod = 1ll * prod * power(i, ans[i]) % P;
	(prod += zero) %= P;
	printf("%d\n", prod);
    return 0;
}