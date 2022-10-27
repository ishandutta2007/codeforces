#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector <int> st1(m * n, -1);
		vector <int> st(m * n, -1);
		vector <vector <int> > a(n, vector <int> (m));
		vector <vector <int> > b(m, vector <int> (n));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				a[i][j]--;
			}
			st[a[i][0]] = i;
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> b[i][j];
				b[i][j]--;
			}
			st1[b[i][0]] = i;
		}
		for(int i = 0; i < n; i++)
		{
			bool fl = 1;
			vector <int> ind(m);
			for(int j = 0; j < m; j++)
			{
				if(st1[a[i][j]] == -1)
				{
					fl = 0;
					break;
				}
				ind[j] = st1[a[i][j]];
			}
			if(!fl)
			{
				continue;
			}
			for(int j = 1; j < n; j++)
			{
				int j1 = b[ind[0]][j];
				j1 = st[j1];
				if(j1 == -1)
				{
					fl = 0;
					break;
				}
				for(int k = 0; k < m; k++)
				{
					if(a[j1][k] != b[ind[k]][j])
					{
						fl = 0;
						break;
					}
				}
			}
			if(fl)
			{
				for(int j = 0; j < n; j++)
				{
					for(int k = 0; k < m; k++)
					{
						cout << b[ind[k]][j] + 1 << " ";
					}
					cout << "\n";
				}
				break;
			}
		}
	}
	return 0;
}