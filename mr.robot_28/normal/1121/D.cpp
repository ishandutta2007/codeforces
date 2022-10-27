#include<bits/stdc++.h>
 
using namespace std;
#define double long double
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vector <int> A(m);
	vector <int> B(s);
	for(int i = 0; i < m; i++)
	{
		cin >> A[i];
	}
	vector <int> cnt(5e5 + 1);
	vector <int> cnt1(5e5 + 1);
	int allcnt = 0;
	for(int i = 0; i < s; i++)
	{
		cin >> B[i];
		cnt[B[i]]++;
	}
	for(int i = 0; i <= 5e5; i++)
	{
		if(cnt[i] != 0)
		{
			allcnt++;
		}
	}
	int j = 0;
	for(int i = 0; i < m; i++)
	{
		while(j < m && allcnt > 0)
		{
			cnt1[A[j]]++;
			if(cnt1[A[j]] == cnt[A[j]])
			{
				allcnt--;
			}
			j++;
		}
		j--;
		if(allcnt > 0)
		{
			break;
		}
		int p = i / k + 1 + (m - j - 1) / k;
		if(p >= n)
		{
			int d = i % k;
			int l, r;
			int cntleft = min(i / k, n - 1);
			int cntright = n - 1 - cntleft;
			l = i - k * cntleft;
			r = max(j, i + k - 1) + cntright * k;
			vector <int> ans;
			for(int w = 0; w < l; w++)
			{
				ans.push_back(w + 1);
			}
			int k1 = k;
			k1 -= s;
			for(int w = i; w <= max(j, i + k - 1); w++)
			{
				if(cnt[A[w]] == 0 && k1 == 0)
				{
					ans.push_back(w + 1);
				}
				else if(cnt[A[w]] > 0)
				{
					cnt[A[w]]--;
				}
				else
				{
					k1--;
				}
			}
			for(int w = r + 1; w < m; w++)
			{
				ans.push_back(w + 1);
			}
			cout << ans.size() << "\n";
			for(int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << " ";
			}
			return 0;
		}
		if(cnt1[A[i]] == cnt[A[i]])
		{
			allcnt++;
		}
		cnt1[A[i]]--;
		j++;
	}
	cout << -1;
	return 0;
}