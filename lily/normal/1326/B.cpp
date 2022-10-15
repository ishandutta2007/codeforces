#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


#define N 201111

int n;
LL a[N];
int b[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(b[i]);
	LL mx = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = mx + b[i];
		mx = max(mx, (LL)a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", a[i]);
	}
}