#include <bits/stdc++.h>
using namespace std;


signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += i / 2;
		if(sum == m)
		{
			for(int j = 0; j <= i; j++)
			{
				cout << j + 1 << " ";
			}
			for(int j = i + 1; j < n; j++)
			{
				cout << (100000000 + 10000 * (j)) << " ";
			}
			return 0;
		}
		if(i != n - 1 && sum < m && sum + (i + 1) / 2 > m)
		{
			for(int j = 0; j <= i; j++)
			{
				cout << j + 1 << " ";
			}
			for(int j = 0; j < i; j++)
			{
				if((i - j + 1) / 2 + sum == m)
				{
					cout << (i + 1) + (j + 1) << " ";
					break;
				}
			}
			for(int j = i + 2; j < n; j++)
			{
				cout << (100000000 + 10000 * j) << " ";
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}