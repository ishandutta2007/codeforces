#include<bits/stdc++.h>
using namespace std;

signed main() {
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		if(n % 4 == 0)
		{
			cout << n / 4 << "\n";
		}
		else if(n % 4 == 1)
		{
			if(n >= 9)
			{
				cout << (n - 9) / 4 + 1 << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if(n % 4 == 2)
		{
			if(n >= 6)
			{
				cout << (n - 6)  /4 + 1 << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else
		{
			if(n >= 15)
			{
				cout << (n - 15) / 4 + 2<< "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}
	return 0;
}