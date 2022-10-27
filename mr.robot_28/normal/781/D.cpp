#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 500;
vector <vector <bitset<N> > > matrix(61, vector <bitset<N> > (N)), matrix1(61, vector <bitset<N> > (N));
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, type;
		cin >> x >> y >> type;
		x--;
		y--;
		if(type == 0)
		{
			matrix[0][x][y] = 1;
		}
		else
		{
			matrix1[0][x][y] = 1;
		}
	}
	int sum = 0;
	int k1 = 60;
	for(int i = 1; i <= k1; i++)
	{
		for(int p = 0; p < n; p++)
		{
			for(int p1 = 0; p1 < n; p1++)
			{
				if(matrix[i - 1][p][p1])
				{
					matrix[i][p] |= matrix1[i - 1][p1];
				}
				if(matrix1[i - 1][p][p1])
				{
					matrix1[i][p] |= matrix[i - 1][p1];
				}
			}
		}
	}
	vector <bitset<N> > newmatrix(N);
	for(int i = 0; i < n; i++)
	{
		newmatrix[i][i] = 1;
	}
	vector <bitset<N> > newmatrix1(N);
	int cnt = 0;
	for(int i = k1; i >= 0; i--)
	{
		bool flag = false;
		for(int p = 0; p < n; p++)
		{
			for(int p1 = 0; p1 < n; p1++)
			{
				if(newmatrix[p][p1])
				{
					if(cnt % 2 == 0)
					{
						newmatrix1[p] |= matrix[i][p1];
					}
					else
					{
						newmatrix1[p] |= matrix1[i][p1];
					}
				}
			}
		}
		for(int p = 0; p < n; p++)
		{
			for(int p1 = 0; p1 <  n; p1++)
			{
				if(newmatrix1[p][p1])
				{
					flag = true;
				}
			}
		}
		if(flag)
		{
			cnt++;
			sum += pow(2, i);
			for(int p = 0; p< n; p++)
			{
				for(int p1 = 0; p1 < n; p1++)
				{
					newmatrix[p][p1] = newmatrix1[p][p1];
				}
			}
		}
		for(int p = 0; p < n; p++)
		{
			newmatrix1[p].reset();
		}
	}
	if(sum > 1e18)
	{
		cout << -1;
	}
	else
	{
		cout << sum;
	}
    return 0;
}