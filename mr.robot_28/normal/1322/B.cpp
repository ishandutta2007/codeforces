#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	vector <vector <vector <int> > > newarr(30, vector <vector <int> > (2));
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		for(int j = 0; j <= 29; j++)
		{
			int k = pow(2, j + 1);
			newarr[j][(A[i] / (k / 2)) % 2].push_back(A[i] % (k / 2));
		}
	}
	for(int i = 0; i < 30; i++)
	{
		if(newarr[i][0].size() != 0)
		{
			sort(newarr[i][0].begin(), newarr[i][0].end());
		}
		if(newarr[i][1].size() != 0)
		{
			sort(newarr[i][1].begin(), newarr[i][1].end());
		}
		int k = pow(2, i);
		int cnt = 0;
		for(int j = 0; j < newarr[i][0].size(); j++)
		{
			int l = -1, r = newarr[i][1].size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(newarr[i][1][midd] + newarr[i][0][j] < k)
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			cnt += l + 1;
			l = j, r = newarr[i][0].size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(newarr[i][0][midd] + newarr[i][0][j] >= k)
				{
					r = midd;
				} 
				else
				{
					l = midd;
				}
			}
			cnt += newarr[i][0].size() - r;
		}
		for(int j = 0; j < newarr[i][1].size(); j++)
		{
			int l = j, r = newarr[i][1].size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(newarr[i][1][midd] + newarr[i][1][j] >= k)
				{
					r = midd;
				}
				else
				{
					l = midd;
				}
			}
			cnt += newarr[i][1].size() - r;
		}
		if(cnt % 2 == 1)
		{
			ans = ans + pow(2, i);
		}
	}
	cout << ans;
	return 0;
}