#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	vector <int> A(n + 1, 0);
	vector<pair<int, int> > W(q);
	for(int i = 0; i < q; i++)
	{
		cin >> W[i].first >> W[i].second;
		for(int j = W[i].first; j <= W[i].second; j++)
		{
			A[j]++;
		}
	}
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(A[i] != 0)
		{
			sum++;
		}
	}
	int max = 0;
	for(int i = 0; i < q; i++)
	{
		cnt = 0;
		vector <int> d(n + 1, 0);
		vector <int> pref(n + 1, 0);
		for(int j = 1; j <= n; j++)
		{
			if(j >= W[i].first && j <= W[i].second)
			{
				if(A[j] == 2)
				{
					d[j] = 1;
				}
				if(A[j] == 1)
				{
					cnt--;
				}
			}
			else
			{
				if(A[j] == 1)
				{
					d[j] = 1;
				}
			}
			pref[j] = pref[j - 1] + d[j];
		}
		int min = 1e9;
		for(int j = i + 1; j < q; j++)
		{
			if(pref[W[j].second] - pref[W[j].first - 1] < min)
			{
				min = pref[W[j].second] - pref[W[j].first - 1];
			}
		}
		if(sum + cnt - min > max)
		{
			max = sum + cnt - min;
		}
	}
	cout << max;
	return 0;
}