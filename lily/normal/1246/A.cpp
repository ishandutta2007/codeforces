#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


LL n, p;

int main() {
	cin >> n >> p;
	for (int i = 1; i <= 1000000; i++) {
		LL cur = n - i * p; 
		if (cur >= i && __builtin_popcountll(cur) <= i) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}