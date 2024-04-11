# include <cstdio>
# include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
int a[1000010];

int g(int x, int v) {
	int ret = 1;
	for(int i = 0; i <= 30; i++) {
		int x0 = x >> i;
		int x1 = x - (x0 << i);
		if(x0 >= v)
			ret = max(ret, 1<<i);
		else if(x0 + 1 >= v)
			ret = max(ret, x1);
		else
			break;
	}
	return ret;
}

ll f(int v) {
	ll ret = 0;
	for(int i = 0; i < n; ++i)
		if(a[i] >= v) ret += g(a[i], v);
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int l = 0, r = 0, mid;
	for(int i = 0; i < n; ++i) r = max(r, a[i] + 1);
	while(r - l > 1) f(mid = (l + r) >> 1) >= k ? l = mid : r = mid;
	printf("%d\n", l ? l : -1);
	return 0;
}