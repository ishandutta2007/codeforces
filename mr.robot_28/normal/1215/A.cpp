#include <bits/stdc++.h>
using namespace std;
int main () {
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if(k1 > k2)
	{
		swap(k1, k2);
		swap(a1, a2);
	}
	int n1 = n;
	int sum1 = 0, sum2 = 0;
	int u = min(n / k1, a1);
	n -= u * k1;
	sum1 += u;
	u = min(n / k2, a2);
	sum1 += u;
	n1 -= min(n1, a1 * (k1 - 1)+ a2 * (k2 - 1));
	sum2 += n1;
	cout << sum2 << " " << sum1;
	return 0;
}