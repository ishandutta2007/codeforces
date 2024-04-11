# include <iostream>
# include <cstdio>
using namespace std;

const int maxn = 200010;

int n, b;
int a[maxn], d[maxn], q[maxn];
long long c[maxn];
int h = 0, t = 0;

int main() {
	scanf("%d%d", &n, &b);
	b += 1;
	for(int i = 0; i < n; ++i) scanf("%d%d", &a[i], &d[i]);
	for(int i = 0; i < n; ++i) {
		while(h < t && c[q[h]] <= a[i]) ++h;
		if(t - h < b) {
			c[i] = (h == t) ? a[i] + d[i] : c[q[t-1]] + d[i];
			q[t++] = i;
		} else {
			c[i] = -1;
		}
	}
	for(int i = 0; i < n; ++i) printf("%I64d%c", c[i], " \n"[i==n-1]);
}