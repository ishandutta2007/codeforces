#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, k;

int main(){
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	cin >> n >> m >> k;
	if (k > n + m - 2)
	{
		printf("-1\n");
		return 0;
	}
	long long ans = 0;
	if (k <= n - 1) ans = n / (k + 1) * m;
	else ans = m / (k - n + 2);
	if (k <= m - 1) ans = max(ans, m / (k + 1) * n);
	else ans = max(ans, n / (k - m + 2));
	cout << ans << endl;
}