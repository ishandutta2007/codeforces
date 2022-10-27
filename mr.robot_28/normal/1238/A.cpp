#include <bits/stdc++.h>

using namespace std;

int main() {
	#define int long long
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;
		x -= y;
		if(x == 1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	return 0;
}