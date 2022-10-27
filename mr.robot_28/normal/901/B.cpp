#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <vector <int> > vec(n + 1, vector <int> (n + 1, 0));
	vec[0][0] = 1;
	vec[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			vec[i][j + 1] += vec[i - 1][j];
			vec[i][j] += vec[i - 2][j];
			vec[i][j] %= 2;
		}
	}
	int maxind1 = 0, maxind2 = 0;
	for(int j = 0; j <= n; j++)
	{
		if(vec[n - 1][j] == 1)
		{
			maxind1 = j;
		}
		if(vec[n][j] == 1)
		{
			maxind2 = j;
		}
	}
	cout << maxind2 << "\n";
	for(int i = 0; i <= maxind2; i++)
	{
		cout << vec[n][i] << " ";
	}
	cout << "\n";
	cout << maxind1 << "\n";
	for(int i = 0; i <= maxind1; i++)
	{
		cout << vec[n - 1][i] << " ";
	}
    return 0;
}