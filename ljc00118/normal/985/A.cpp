#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

int a[N];
int n;

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
	scanf("%d", &n);
	for(int i = 1; i <= n / 2; i++) scanf("%d", &a[i]);
	sort(a + 1, a + (n / 2) + 1);
	int ans = 0, tmp = 0;
	for(int i = 1; i <= n; i += 2) ans += abs(a[(i + 1) / 2] - i);
	for(int i = 2; i <= n; i += 2) tmp += abs(a[i / 2] - i);
	printf("%d\n", min(ans, tmp));
	return 0;
}