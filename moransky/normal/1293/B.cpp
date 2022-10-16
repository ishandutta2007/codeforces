#include <cstdio>
#include <iostream>
using namespace std;
int n;
double ans = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ans += 1.0 / i;
	}
	cout << ans << endl;
	return 0;
}