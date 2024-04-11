# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

int a[100010], n;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) a[i] = a[i] - a[i + 1];
	for(int i = 0; i < n; ++i) if(a[i] < 0) a[i] = -a[i];
	long long s = 0, ans = 0, mins = 0;
	for(int i = 0; i < n-1; ++i) {
		if (~i&1) mins = min(mins, s);
		s += (~i & 1) ? a[i] : -a[i];
		ans = max(ans, s - mins);
	}
	s = 0, mins = 0;
	for(int i = 1; i < n-1; ++i) {
		if (i&1) mins = min(mins, s);
		s += (i & 1) ? a[i] : -a[i];
		ans = max(ans, s - mins);
	}
	printf("%I64d\n", ans);
	return 0;
}