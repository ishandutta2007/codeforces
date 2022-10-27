#include<bits/stdc++.h>
 
using namespace std;
#define int unsigned long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		swap(n, m);
		vector <int> A(n);
		int sum = 0;
		vector <int> cnt(60);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			sum += A[i];
			int cnt1 = 0;
			while(A[i] > 1)
			{
				A[i] = A[i] / 2;
				cnt1++;
			}
			cnt[cnt1]++;
		}
		if(sum < m)
		{
			cout << -1 << "\n";
		}
		else
		{
			vector <int> powers;
			n = m;
			while(n > 0)
			{
				powers.push_back(n % 2);
				n = n / 2;
			}
			int sum = 0;
			int j = 0;
			int ans = 0;
			for(int i = 0; i < powers.size(); i++)
			{
				if(!powers[i])
				{
					sum += (1 << i) * cnt[i];
					continue;
				}
				sum += (1 << i) * cnt[i];
				if(sum >= (1 << i))
				{
					sum -= (1 << i);
				}
				else
				{
					int l = 0;
					for(int j = i + 1; j < 60; j++)
					{
						if(cnt[j] >= 1)
						{
							l = j;
							cnt[j]--;
							break;
						}
					}
					for(int d = i; d < l; d++)
					{
						ans++;
						cnt[d]++;
					}
					sum += (1 << i);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}