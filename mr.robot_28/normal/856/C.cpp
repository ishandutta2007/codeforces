#include<bits/stdc++.h>
using namespace std;
const int const1 = 998244353;
void re(int &a)
{
	if(a >= const1)
	{
		a -= const1;
	}
}
signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int t;
  	cin >> t;
  	for(int e = 0; e < t; e++)
  	{
  		int n;
	  	cin >> n;
  		vector <pair <int, int> > a(n);
  		int cnt = 0;
  		vector <int> fact(n + 1);
  		fact[0] = 1;
  		vector <int> b(n);
	  	for(int i = 0; i < n; i++)
 	 	{
 	 		fact[i + 1] = 1LL * fact[i] * (i + 1) % const1;
  			int c;
  			cin >> c;
  			b[i] = c;
  			int kol = 0, sum = 0;
  			while(c > 0)
  			{
  				kol++;
  				if(kol % 2 == 0)
  				{
  					sum += c % 10;
				}
				else
				{
					sum += (11 - c % 10) % 11;
				}
  				c /= 10;
			}
			sum %= 11;
			if(kol % 2 == 1)
			{
				cnt++;
				sum = (11 - sum) % 11;
			}
			a[i] = {sum, kol};
		}
		if(cnt == 0)
		{
			int sum = 0;
			for(int i = 0; i < n; i++)
			{
				sum += a[i].first;
			}
			sum %= 11;
			if(sum == 0)
			{
				int ans = 1;
				for(int i = 1; i <= n; i++)
				{
					ans = 1LL * ans * i % const1;
				}
				cout << ans << "\n";
			}
			else{
				cout << 0 << "\n";
			}
			continue;
		}
		vector <vector <int> > dp(n + 1, vector <int> (11, 0));
		vector <vector <int> > dp2(n + 1, vector <int> (11));
		dp[0][0] = 1;
		int c1 = (cnt + 1) / 2;
		int c2 = (cnt) / 2;
		cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i].second & 1)
			{
				for(int j = cnt; j >= 0; j--)
				{
					vector <int> mass(11);
					for(int k = 0; k <= 10; k++)
					{
						mass[k] = dp[j][k];
						dp[j][k] = 0;
					}
					for(int k = 0; k <= 10; k++)
					{
						if(j < c1)
						{
							dp[j + 1][(k + a[i].first) % 11] += 1LL * mass[k] * (j + 1) % const1;
							re(dp[j + 1][(k + a[i].first) % 11]);
						}
						if(cnt - j < c2)
						{
							dp[j][(k + 11 - a[i].first) % 11] += 1LL * mass[k] * (cnt - j + 1) % const1;
							re(dp[j][(k + 11 - a[i].first) % 11]);
						}
					}
				}
				cnt++;
			}
		}
		vector <vector <int> > dp1(n + 1, vector <int> (11));
		dp1[0][0] = 1;
		int p = 0;
		for(int i = 0; i < n; i++)
		{
			if(!(a[i].second & 1))
			{
				for(int r = 0; r <= p + 1; r++)
				{
					for(int j = 0; j <= 10; j++)
					{
						dp2[r][j] = 0;
					}
				}
				for(int r = 0; r <= p; r++)
				{
					for(int j = 0; j <= 10; j++)
					{
						dp2[r + 1][(j + a[i].first) % 11] += 1LL * dp1[r][j] * (c1 + r) % const1;
						re(dp2[r + 1][(j + a[i].first) % 11]);
						int w = c1;
						if(c2 == c1)
						{
							w++;
						}
						dp2[r][(j + 11 - a[i].first) % 11] += 1LL * dp1[r][j] * (w + p - r) % const1;
						re(dp2[r][(j + 11 - a[i].first) % 11]);
					}
				}
				for(int r = 0; r <= p + 1; r++)
				{
					for(int j = 0; j <= 10; j++)
					{
						dp1[r][j] = dp2[r][j];
					}
				}
				p++;
			}
		}
		int ans = 0;
		for(int a = 0; a <= 10; a++)
		{
			int b = (11 - a) % 11;
			for(int t = 0; t <= p; t++)
			{
				ans += (1LL *dp1[t][b] * dp[c1][a] % const1);
				re(ans);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}