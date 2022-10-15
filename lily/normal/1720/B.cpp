#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)


int main() {
	int T;
	read(T);
	while (T--) {
		int n;
		read(n);
		vector <int> a;
		for (int i = 0; i < n; i++) {
			int x;
			read(x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		printf("%d\n", a[n - 1] + a[n - 2] - a[1] - a[0]);
	}
}