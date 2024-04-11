#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)


int n;
int main() {
	int T;
	read(T);
	while (T--) {
		int n;
		read(n);
		vector <int> a;
		for (int i = 1; i <= n; i++) {
			int x; read(x); a.push_back(x);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, a[i] - a[(i + 1) % n]);
		}
		for (int i = 1; i < n; i++) {
			ans = max(ans, a[i] - a[0]);
		}
		for (int i = 0; i < n - 1; i++) {
			ans = max(ans, a[n - 1] - a[i]);
		}
		printf("%d\n", ans);
 	}


}