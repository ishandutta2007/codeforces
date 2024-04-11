#include <bits/stdc++.h> 
using namespace std;
int main()
{
	#define int long long
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector <int> A(n), B(m);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> B[i];
	}
	if(k >= n || k >= m)
	{
		cout << -1;
		return 0;
	}
	for(int i = k; i >= 0; i--)
	{
		if(A[i] + ta > B[B.size() - 1 +i - k])
		{
			cout << -1;
			return 0;
		}
	}
	int max1 = 0;
	int x = 0, cnt = 0;
	for(int i = 0; i <= k; i++)
	{
		int l = -1, r = m;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(B[midd] >= A[i] + ta)
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		if(r + k - i >= m)
		{
			cout << -1;
			return 0;
		}
		else
		{
			max1 = max(max1, B[r + k - i]);
		}
	}
	cout << max1 + tb;
   	return 0;
}