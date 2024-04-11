#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <pair <int, int> > to;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <char> > A(n, vector <char> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	vector <char> vec;
	vec.push_back('A');
	vec.push_back('G');
	vec.push_back('C');
	vec.push_back('T');
	vector <vector <char> > ans(n, vector <char> (m));
	vector <vector <char> > ans1(n, vector <char> (m));
	int anssum = 1e9;
	for(int i = 0; i < 4; i++)
	{
		for(int j = i + 1; j < 4; j++)
		{
			char t1 = 'w', t2 = 'w', t3 = vec[i], t4 = vec[j];
			for(int d = 0; d < 4; d++)
			{
				if(d != i && d != j)
				{
					if(t1 == 'w')
					{
						t1 = vec[d];
					}
					else
					{
						t2 = vec[d];
					}
				}
			}
			int sum = 0;
			for(int x = 0; x < n; x++)
			{
				int ns1 = 0, ns2 = 0;
				for(int y = 0; y < m; y++)
				{
					if(y % 2 == 0)
					{
						ns1 += (A[x][y] != t1);
						ns2 += (A[x][y] != t2);
					}
					else
					{
						ns2 += (A[x][y] != t1);
						ns1 += (A[x][y] != t2);
					}
				}
				sum += min(ns1, ns2);
				for(int y = 0; y < m; y++)
				{
					if(ns1 < ns2)
					{
						if(y % 2 == 0)
						{
							ans1[x][y] = t1;
						}
						else
						{
							ans1[x][y] = t2;
						}
					}
					else
					{
						if(y % 2 == 0)
						{
							ans1[x][y] = t2;
						}
						else
						{
							ans1[x][y] = t1;
						}
					}
				}
				swap(t1, t3);
				swap(t2, t4);
			}
			if(sum < anssum)
			{
				anssum = sum;
				for(int x = 0; x < n; x++)
				{
					for(int y = 0; y < m; y++)
					{
						ans[x][y] = ans1[x][y];
					}
				}
			}
			t1 = 'w', t2 = 'w', t3 = vec[i], t4 = vec[j];
			for(int d = 0; d < 4; d++)
			{
				if(d != i && d != j)
				{
					if(t1 == 'w')
					{
						t1 = vec[d];
					}
					else
					{
						t2 = vec[d];
					}
				}
			}
			sum = 0;
			for(int y = 0; y < m; y++)
			{
				int ns1 = 0, ns2 = 0;
				for(int x = 0; x < n; x++)
				{
					if(x % 2 == 0)
					{
						ns1 += (A[x][y] != t1);
						ns2 += (A[x][y] != t2);
					}
					else
					{
						ns1 += (A[x][y] != t2);
						ns2 += (A[x][y] != t1);
					}
				}
				sum += min(ns1, ns2);
				for(int x =0; x < n; x++)
				{
					if(ns1 < ns2)
					{
						if(x % 2 == 0)
						{
							ans1[x][y] = t1;
						}
						else{
							ans1[x][y] = t2;
						}
					}
					else{
						if(x % 2 == 0)
						{
							ans1[x][y] = t2;
						}
						else
						{
							ans1[x][y] = t1;
						}
					}
				}
				swap(t1, t3);
				swap(t2, t4);
			}
			if(sum < anssum)
			{
				anssum = sum;
				for(int x = 0; x < n; x++)
				{
					for(int y = 0; y < m; y++)
					{
						ans[x][y] = ans1[x][y];
					}
				}
			}
		}
	}
	for(int x = 0; x < n; x++)
	{
		for(int y = 0; y < m; y++)
		{
			cout << ans[x][y];
		}
		cout << "\n";
	}
    return 0;
}