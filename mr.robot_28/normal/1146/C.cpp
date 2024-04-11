#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout.flush();
		cout << 1 << " " << n - 1 << " ";
		for(int j = 1; j <= n; j++)
		{
			cout << j << " ";
		}
		int d;
		cin >> d;
		int l = 1, r = n + 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			cout.flush();
			cout << 1 << " " << midd - 1 << " ";
			for(int j = 1; j <= midd; j++)
			{
				cout << j << " ";
			} 
			cout << endl;
			int d1;
			cin >> d1;
			if(d1 == d)
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		cout << 1 << " " << n - 1 << " ";
		cout << r << " ";
		for(int j = 1; j<= n; j++)
		{
			if(j != r)
			{
				cout << j << " ";
			}
		}	
		int maxd;
		cin >> maxd;
		cout << -1 << " " << maxd << endl;
	}
	return 0;
}