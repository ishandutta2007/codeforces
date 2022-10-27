#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
signed main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end(), cmp);
	vector <int> postmin(n, 1e9), postcntmin(n, 0);
	for(int i = n - 1; i >= 0; i--)
	{
		int l = -1, r = n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(A[midd].second >= A[i].first)
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		if(r == n)
		{
			if(i == n- 1)
			{
				postmin[i] = A[i].second;
				postcntmin[i] = 1;
			}
			else
			{
				if(A[i].second == postmin[i + 1])
				{
					postmin[i] = postmin[i + 1];
					postcntmin[i] = (postcntmin[i + 1] + 1) % CONST;
				}
				else if(A[i].second < postmin[i + 1])
				{
					postcntmin[i] = 1;
					postmin[i] = A[i].second;
				}
				else
				{
					postmin[i] = postmin[i + 1];
					postcntmin[i] = postcntmin[i + 1];
				}
			}
		}
		else
		{
			int v = postmin[r] - A[i].first + A[i].second;
			int cnt = postcntmin[r];
			if(v < postmin[i + 1])
			{
				postmin[i] = v;
				postcntmin[i] = cnt;
			}
			else if(v == postmin[i + 1])
			{
				postcntmin[i] = (postcntmin[i + 1] + cnt) % CONST;
				postmin[i] =v;
			}
			else
			{
				postmin[i] = postmin[i + 1];
				postcntmin[i] = postcntmin[i + 1];
			}
		}
		//cout << postmin[i] << " " << postcntmin[i] << "\n";
	}
	cout << postcntmin[0];
    return 0;
}