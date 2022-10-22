#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10, V = 1e9;
int a[N];

int solve() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	i64 lcm = 1;
	for(int i = 1; i <= n; i++) {
		if(lcm > V) continue;
		int flag = 0;
		for(int j = 2; j <= i + 1; j++) {
			if(a[i] % j) {
				flag = 1;
				break;
			}
		}
		if(!flag) return 0;
		lcm = lcm / __gcd(lcm, (i64)(i + 1)) * (i + 1);
	}
	return 1;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) {
		printf(solve() ? "YES\n" : "NO\n");
	}
	return 0;
}