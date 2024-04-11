#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10;
int n, m;
int a[N];
map<int, int> vis;
void Add(int &x, int y) {if((x += y) >= m && (x -= m));}

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % m)
		if(b & 1)
			c = 1ll * c * a % m;
	return c;
}

void check(int pos, int sum) {
	vis.clear();
	for(int i = 1; i <= n; i++) vis[a[i]] = 1;
	int x = a[pos];
	int d = 1ll * (sum - 1ll * n * x % m + m) % m * power(1ll * n * (n - 1) / 2 % m, m - 2) % m;
	for(int i = 0; i < n; i++) {
		int v = (x + 1ll * d * i % m) % m;
		if(!vis[v]) return;
		else vis[v] = 0;
	}
	printf("%d %d\n", x, d);
	exit(0);
}

void ocheck(int d, int sum) {
	vis.clear();
	for(int i = 1; i <= n; i++) vis[a[i]] = 1;
	int x = (sum - 1ll * n * (n - 1) / 2 % m * d % m + m) % m;
	x = 1ll * x * power(n, m - 2) % m;
	for(int i = 0; i < n; i++) {
		int v = (x + 1ll * d * i % m) % m;
		if(!vis[v]) return;
		else vis[v] = 0;
	}
	printf("%d %d\n", x, d);
	exit(0);
}

int main() {
	scanf("%d%d", &m, &n);
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		Add(sum, a[i]);
	}
	if(n == m) {
		printf("%d %d\n", 0, 1);
		exit(0);
	}
	if(n <= 1000) {
		for(int i = 1; i <= n; i++) {
			check(i, sum);
		}
		printf("-1\n");
		exit(0);
	}
	int mid = 1ll * sum * power(n, m - 2) % m;
	int sum2 = 0;
	for(int i = 1; i <= n; i++) {
		Add(sum2, 1ll * (a[i] - mid) * (a[i] - mid) % m);
	}
	int d2 = sum2, f = 0;
	int cmid = 1ll * (n - 1) * power(2, m - 2) % m;
	for(int i = 0; i < n; i++) {
		Add(f, 1ll * (cmid - i) * (cmid - i) % m);
	}
	d2 = 1ll * d2 * power(f, m - 2) % m;
	int d = -1;
	for(int i = 2; i <= n; i++) {
		if(1ll * (a[i] - a[1]) * (a[i] - a[1]) % m == d2) {
			d = (a[i] - a[1] + m) % m;
			break;
		}
	}
	if(d == -1) {
		printf("-1\n");
		exit(0);
	}
	ocheck(d, sum);
	printf("-1\n");
	return 0;
}