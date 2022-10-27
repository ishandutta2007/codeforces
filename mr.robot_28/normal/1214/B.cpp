#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int b, g, n;
	cin >> b >> g >> n;
	int t = min(b + 1, min(g + 1, n + 1));
	cout << min(b + g - n + 1, t);
	return 0;
}