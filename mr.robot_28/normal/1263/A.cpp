#include <bits/stdc++.h>

using namespace std;


int main() {	
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a > b)
		{
			swap(a, b);
		}
		if(b > c)
		{
			swap(b, c);
		}
		if(a > b)
		{
			swap(a, b);
		}
		int cnt = min(a, c - b);
		a -= cnt;
		c -= cnt;
		int d1 = a / 2;
		int d2 = a / 2 + a % 2;
		cnt += min(b, d1);
		cnt += min(c, d2);
		b -= min(b, d1);
		c -= min(c, d2);
		cnt += min(b, c);
		cout << cnt << "\n";
	}
	return 0;
}