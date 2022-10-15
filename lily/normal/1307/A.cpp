#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

int n, D;
int a[13123];

void work() {
	read(n) ; read(D);
	for (int i = 1; i <= n ;i++) {
		read(a[i]);
	}
	for (int i = 2; i <= n; i++) {
		if (D <= a[i] * (i - 1)) {
			a[1] += D / (i - 1);
			break;
		}
		else {
			D -= a[i] * (i - 1);
			a[1] += a[i];
		}
	}
	cout << a[1] << endl;

}

int main() {
	int T;
	read(T);
	while (T--) work();

}