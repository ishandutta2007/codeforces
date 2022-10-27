#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int q;
	cin >> q;
	for(int k = 0; k < q; k++)
	{
		int n, m;
		cin >> n >> m;
		vector <vector <char> > A(n, vector <char> (m));
		vector <int> cntx(n), cnty(m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> A[i][j];
				if(A[i][j] == '.')
				{
					cntx[i]++;
					cnty[j]++;
				}
			}
		}
		int min1 = 1e9;
		for(int i = 0; i < n; i++)
		{
			for(int j =0; j < m; j++)
			{
				if(A[i][j] == '.')
				{
					min1 = min(min1, cntx[i] + cnty[j] - 1);
				}
				else
				{
					min1 = min(min1, cntx[i] + cnty[j]);
				}
			}
		}
		cout << min1 << "\n";
	}
	return 0;
}