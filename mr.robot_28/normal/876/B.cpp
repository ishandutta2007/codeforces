#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
const int inf = 1e9;
int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <vector <int> > B(n);
	map <int, int> K;
	for(int i = 0; i < n; i++)
	{
		if(K.count(A[i] % m) == 0)
		{
			K[A[i] % m] = i;
			B[i].push_back(i);
		}
		else
		{
			B[K[A[i] % m]].push_back(i);
		}
	}
	for(int i = 0; i < B.size(); i++)
	{
		if(B[i].size() >= k)
		{
			cout << "Yes" << endl;
			for(int j = 0; j < k; j++)
			{
				cout << A[B[i][j]] << " ";
			}
			return 0;
		}
	}
	cout << "No";
	return 0;
}