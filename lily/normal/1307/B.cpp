#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

int n, X;
int a[1231231];

void work() {
	read(n); read(X);
	int mx = 0;
	bool eq = 0;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		eq |= a[i] == X;
		mx = max(mx, a[i]);
	}
	if (eq) cout << 1 << endl;
	else cout << max(2, (X + mx - 1) / mx) << endl;
}

int main() {
	int T;
	read(T);
	while (T--) work();

}