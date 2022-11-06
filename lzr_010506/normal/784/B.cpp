#include <bits/stdc++.h>
using namespace std;
int b[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0};
int main()
{
	int a;
	cin >> a;
	int ans = 0;
	if(a == 0) ans ++;
	while(a)
	{
		int x = a % 16;
		ans += b[x];
		a /= 16;
	}
	cout << ans;
	return 0;
}