#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	vector <int> A(n);
	vector <int> B(m);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int j = 0; j < m; j++)
	{
		cin >> B[j];
	}
	int i1, j1;
	for(int i = 0; i < n; i++)
	{
		if(A[i] % p != 0)
		{
			i1 = i;
			break;
		}
	}
	for(int j = 0; j < m; j++)
	{
		if(B[j] % p != 0)
		{
			j1 = j;
			break;
		}
	}
	cout << i1 + j1;
	return 0;
}