#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;

int a[N];
int n, m, k;

inline int read() {
	int f = 0, fu = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') fu = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		f = (f << 3) + (f << 1) + c - 48;
		c = getchar();
	}
	return f * fu;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	sort(a + 1, a + (n * m) + 1);
	int tmp;
	for(tmp = 1; tmp <= n * m && a[tmp] - a[1] <= k; tmp++);
	tmp--;
	if(tmp < n) {
		printf("0\n");
		return 0;
	}
	long long ans = 0;
	int kexuan = n * m - tmp;
	for(int i = tmp; i >= 1; i--) {
		if(kexuan >= (m - 1)) {
			ans += (long long)a[i];
			kexuan -= (m - 1);
		}
		else kexuan++;
	}
	printf("%lld\n", ans);
	return 0;
}