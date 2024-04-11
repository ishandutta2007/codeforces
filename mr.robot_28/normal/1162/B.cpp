#include <bits/stdc++.h>

using namespace std;

int main() {
	#define int long long
	int n, m;
	cin >> n >> m;
	vector <vector <int> > A(n, vector <int> (m)), B(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> B[i][j];
		}
	}
	vector <vector <int> > C(n, vector <int> (m)), C1(n, vector <int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			C[i][j] = min(A[i][j], B[i][j]);
			C1[i][j] = max(A[i][j], B[i][j]);
			if(j != 0 &&  (C[i][j] <= C[i][j - 1] || C1[i][j] <= C1[i][j - 1]))
			{
				cout << "Impossible";
				return 0;
			}
			if(i != 0 && (C[i][j] <= C[i - 1][j] || C1[i][j] <= C1[i - 1][j]))
			{
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	return 0;
}