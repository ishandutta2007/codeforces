#include<bits/stdc++.h>
#define gc() getchar()

using namespace std;

const int N = 100000 + 10;

map <int, int> f;

int a[N], b[N], x[N], y[N];
int n, m;
long long ans = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &x[i]);
		ans += (long long)x[i];
		if(f[a[i]] == 0) f[a[i]] = x[i];
		else if(f[a[i]] >= x[i]) ans -= x[i];
		else ans -= f[a[i]], f[a[i]] = x[i];
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &b[i], &y[i]);
		ans += (long long)y[i];
		if(f[b[i]] == 0) f[b[i]] = y[i];
		else if(f[b[i]] >= y[i]) ans -= y[i];
		else ans -= f[b[i]], f[b[i]] = y[i];
	}
	cout << ans;
	return 0;
}