#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if(n > m) swap(n, m);
	int ans = n * (m / 2);
	if(m % 2 == 1) ans += n / 2;
	cout << ans;
	return 0;
}