#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > A(n);
	vector <int> P(n, 1e9);
	for(int i =0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		A[a - 1].push_back(b - 1);
	}
	for(int s = 0; s < n; s++)
	{
		int max1 = 0;
		for(int i = 0; i  < n; i++)
		{
			if(A[i].size() != 0)
			{
				int u = (A[i][0] - i + n) % n;
				int min =((i - s + n) %n + (A[i].size() - 1) * n);
				for(int j = 1; j < A[i].size(); j++)
				{
					int t = (A[i][j] - i + n) % n;
					if(t < u)
					{
						u = t;
					}
				}
				min += u;
				max1 = max(max1, min);
			}
		}
		cout << max1 << " ";
	}
	return 0;
}