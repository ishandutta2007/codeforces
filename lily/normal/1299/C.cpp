#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second
#define N int(1e6 + 7)
const double eps = 1e-8;
int n;
int a[N], sta[N];
double b[N], ans[N];
int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	int top = 0;
	for (int i = 1; i <= n; i++) {
		while(top && (b[i] - b[sta[top - 1]]) / (i - sta[top-1]) < eps + (b[sta[top]] - b[sta[top - 1]]) / (sta[top] - sta[top - 1])) top--;
		sta[++top] = i;
	}
	int cur = 0;
	for (int i = 1; i <= top; i++) {
		for (int j = cur + 1; j <= sta[i]; j++)
			ans[j] = (b[sta[i]] - b[cur]) / (sta[i] - cur);
		cur = sta[i];
	}
	for (int i = 1; i <= n; i++) {
		printf("%.9lf\n", ans[i]);
	}
}