#include <bits/stdc++.h>

using namespace std;
signed main() {
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > A;
	vector <int> M(n);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		A.push_back({x, y});
	}
	int x = A[0].first, cnt = 0;
	for(int i = 0; i < m; i++)
	{
		if(A[i].first != x && A[i].second != x)
		{
			cnt++;
			M[A[i].first - 1]++;
			M[A[i].second - 1]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(M[i] == cnt)
		{
			cout << "YES";
			return 0;
		}
		M[i] = 0;
	}
	cnt = 0;
	x = A[0].second;
	for(int i = 0; i < m; i++)
	{
		if(A[i].first != x && A[i].second != x)
		{
			cnt++;
			M[A[i].first - 1]++;
			M[A[i].second - 1]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(M[i] == cnt)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}