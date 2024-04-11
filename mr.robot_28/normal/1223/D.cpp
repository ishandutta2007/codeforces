#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int q;
	cin >> q;
	for(int f = 0; f < q; f++)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		vector <int> first(n, -1), last(n, -1);
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
			if(first[A[j] - 1] == -1)
			{
				first[A[j] - 1] = j;
			}
			last[A[j] - 1] = j;
		}
		vector <pair <int, int> > k;
		for(int i = 0; i < n; i++)
		{
			if(first[i] != -1)
			{
				k.push_back({first[i], last[i]});
			}
		}
		if(k.size() == 0)
		{
			cout << 0 << "\n";
		}
		else
		{
			vector <int> leftmax(k.size()), rightmax(k.size());
			for(int i = 0; i < k.size() - 1; i++)
			{
				if(k[i].second > k[i + 1].first)
				{
					leftmax[i + 1] = i + 1;
				}
				else
				{
					leftmax[i + 1] = leftmax[i];
				}
			}
			for(int i = k.size() - 1; i > 0; i--)
			{
				if(k[i].first < k[i - 1].second)
				{
					rightmax[i - 1] = k.size() - i;
				}
				else
				{
					rightmax[i - 1] = rightmax[i];
				}
			}
			int max = 1e9;
			for(int i = 0; i < k.size(); i++)
			{
				if(leftmax[i] + rightmax[i] < max)
				{
					max = leftmax[i] + rightmax[i];
				}
			}
			cout << max << "\n";
		}
	}
	return 0;
}