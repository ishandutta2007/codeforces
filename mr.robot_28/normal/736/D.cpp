#include <bits/stdc++.h>
                  
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > mass(m);
	bitset<2000> repr[2000];
	bitset<2000> matrix[2000];
	for(int i = 0; i < n; i++)
	{
		repr[i].reset();
		matrix[i].reset();
	}
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		mass[i] = {a, b};
		matrix[a][b] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		repr[i][i] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		int ci = -1;
		for(int j = 0; j < n; j++)
		{
			if(matrix[j][i])
			{
				ci = j;
			}
		}
		swap(matrix[i], matrix[ci]);
		swap(repr[i], repr[ci]);
		for(int j = 0; j < n; j++)
		{
			if(i != j && matrix[j][i])
			{
				matrix[j] ^= matrix[i];
				repr[j] ^= repr[i];
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(repr[mass[i].second][mass[i].first] == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}