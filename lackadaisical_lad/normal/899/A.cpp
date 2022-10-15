#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a = 0, b = 0;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		if (t == 1)
			a++;
		else
			b++;
	}
	int ans = min(a, b);
	a -= ans;
	ans += a / 3;
	cout << ans;
	return 0;
}