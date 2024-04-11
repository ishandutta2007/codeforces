#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 =998244353;
signed main() {
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int n, k, m;
  	cin >> n >> k >> m;
  	int sumx = 0;
  	vector <vector <pair <int, int> > > events(n);
  	vector <pair <pair <int, int>, int> > p(m);
  	vector <int> left(k, 0);
  	vector <int> right(k, -1);
  	for(int i = 0; i < m; i++)
  	{
  		int l, r, x;
  		cin >> l >> r >> x;
  		l--;
  		r--;
  		p[i] = {{l, r}, x};
  		sumx |= ((1 << k) - 1 - x);
  		events[l].push_back({i, -1});
  		events[r].push_back({i, 1});
	}
  	vector <int> cnt(k);
  	vector <vector <int> > ans(n, vector <int> (k));
  	vector <int> sum(k, 0);
  	vector <int> Power(n + 1);
  	Power[0] = 1;
  	for(int i = 1; i <= n; i++)
  	{
  		Power[i] = (Power[i - 1] * 2) % const1;
  	}
  	for(int i = 0; i < n; i++)
  	{
  		for(int j = 0; j < events[i].size(); j++)
  		{
  			int ind = events[i][j].first;
  			int type = events[i][j].second;
  			int x = p[ind].second;
  			if(type == -1)
  			{
  				for(int p = 0; p < k; p++)
  				{
  					if(((1 << p) & x) != 0)
  					{
  						cnt[p]++;
  					}
  				}
  			}
  		}
  		for(int j = 0; j < k; j++)
  		{
  			if(cnt[j] == 0)
  			{
  				ans[i][j] += sum[j];
  				if(left[j] == 0){
  					ans[i][j]++;
  				}
  				while(ans[i][j] >= const1)
  				{
  					ans[i][j] -= const1;
  				}
  				sum[j] += ans[i][j];
  				while(sum[j] >= const1)
  				{
  					sum[j] -= const1;
  				}
  			}
  		}
  		for(int j = 0; j < events[i].size(); j++)
  		{
  			int ind = events[i][j].first;
  			int type = events[i][j].second;
  			if(type == 1)
  			{
  				int l = p[ind].first.first;
  				int x = p[ind].second;
  				for(int p = 0; p < k; p++)
  				{
  					if(((1 << p) & x) == 0)
  					{
  						if(right[p] == -1)
  						{
  							right[p]++;
  						}
  						while(right[p] < l)
  						{
  							sum[p] -= ans[right[p]][p];
  							if(sum[p] < 0)
  							{
  								sum[p] += const1;
  							}
  							right[p]++;
  						}
  					}
  				}
  			}
  		}
		for(int j = 0; j < events[i].size(); j++)
  		{
  			int ind = events[i][j].first;
  			int type = events[i][j].second;
  			if(type == 1)
  			{
  				int l = p[ind].first.first;
  				int x = p[ind].second;
  				for(int p = 0; p < k; p++)
  				{
  					if(((1 << p) & x) != 0)
  					{
  						cnt[p]--;
  					}
  					else
  					{
  						left[p]++;
  					}
  				}
  			}
  		}
  	}
  	int res = 1;
  	for(int i = 0; i < k; i++)
  	{
  		int cnt = 0;
  		if((sumx & (1 << i)) == 0)
  		{
  			cnt++;
  		}
  		cnt += sum[i];
  		res = (res * cnt) % const1;
  	}
  	cout << res;
    return 0;
}