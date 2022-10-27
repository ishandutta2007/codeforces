#include<bits/stdc++.h> 

using namespace std; 

int main() { 
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
			bool T = false;
			for(int u = 0; u < n; u++)
			{
				if(i + j - u >= 0 && i + j - u < m && A[u][i + j - u] == B[i][j])
				{
					A[u][i + j - u] = 0;
					T = true;
					break;
				}
			}
			if(!T)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}