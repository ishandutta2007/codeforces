#include <bits/stdc++.h>
using namespace std;
double n, x, y, ans;
int main()
{
	cin >> n >> x >> y;
	double s = y / 100.0;
	while((x + ans) / n < s)
		ans ++;
	cout << ans;
	return 0;
}