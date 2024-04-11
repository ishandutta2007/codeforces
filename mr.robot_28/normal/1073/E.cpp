#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 998244353;
int pow1(int a, int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n == 1)
	{
		return a;
	}
	else if(n % 2 == 0)
	{
		int y = pow1(a, n / 2);
		return y * y % CONST;
	}
	else
	{
		int y = pow1(a, n / 2);
		return a * (y * y % CONST) % CONST;
	}
}
int ans(int n, int k)
{
	int cnt = 0, d = n;
	vector <int> A;
	while(d > 0)
	{
		cnt++;
		A.push_back(d % 10);
		d = d / 10;
	}
	for(int i = 0; i < A.size() / 2; i++)
	{
		swap(A[i], A[A.size() - i - 1]);
	}
	vector <vector <vector <int> > > dp(cnt, vector <vector <int> > (10, vector <int> (1024, 0)));
	vector <vector <vector <int> > > SUM(cnt, vector <vector <int> > (10, vector <int> (1024, 0)));
	vector <vector <int> > dp1(cnt, vector <int> (1024, 0));
	vector <vector <int> > SUM1(cnt, vector <int> (1024, 0));
	for(int i = cnt - 1; i >= 0; i--)
	{
		if(i == cnt - 1)
		{
			for(int j = 0; j < 10; j++)
			{
				if(j != 0 || i != 0)
				{
					dp[i][j][1 << j] = 1;
					SUM[i][j][1 << j] = j;
					dp1[i][1 << j]++;
					SUM1[i][1 << j] += j;
				}
			}
		}
		else
		{
			for(int j = 0; j < 10; j++)
			{
				if(j != 0 || i != 0){
					for(int k1 = 1; k1 < 1024; k1++)
					{
						SUM[i][j][k1 | (1 << j)] =(((dp1[i + 1][k1] * pow1(10, cnt - 1 - i) % CONST) * j % CONST + SUM1[i + 1][k1]) % CONST + SUM[i][j][k1 | (1 << j)]) % CONST;
						dp[i][j][k1 | (1 << j)] = (dp[i][j][k1 | (1 << j)] + dp1[i + 1][k1]) % CONST;
						dp1[i][k1 | (1 << j)] = (dp1[i][k1 |(1 << j)] +dp1[i + 1][k1]) % CONST;
						SUM1[i][k1 | (1 << j)] = (((dp1[i + 1][k1] * pow1(10, cnt - 1 - i) % CONST) * j % CONST + SUM1[i + 1][k1]) % CONST + SUM1[i][k1 | (1 << j)]) % CONST;
					}
				}
			}
		}
	}
	int ans = 0;
	int R = 0;
	for(int i = 0; i < A.size(); i++)
	{
		for(int d = 0; d < A[i]; d++)
		{
			if(i != 0 || d != 0)
			{
				for(int j = 0; j < 1024; j++)
				{
					int u = j;
					for(int p = 0; p < i; p++)
					{
						u = u | (1 << (A[p]));
					}
					int cnt = 0;
					int u1 = u;
					while(u > 0)
					{
						cnt += u % 2;
						u = u / 2;
					}
					if(cnt <= k)
					{
						ans = ((ans + SUM[i][d][j]) % CONST + dp[i][d][j] * R % CONST) % CONST;
					}
				}
			}
		}
		R = ( R + A[i] * pow1(10, A.size() - i - 1) % CONST) % CONST;
	}
	int ep = 0, n1 = n;
	while(n1 > 0)
	{
		ep = ep | (1 << (n1 % 10));
		n1 = n1 / 10;
	}
	int sum = 0;
	while(ep > 0)
	{
		sum += ep % 2;
		ep = ep / 2;
	}
	if(sum <= k)
	{
		ans += n;
	}
	for(int i = 1; i < A.size(); i++)
	{
		for(int j = 1; j < 10; j++)
		{
			for(int k1 = 0; k1 < 1024; k1++)
			{
				int e = k1, cnt = 0;
				while(e > 0)
				{
					cnt += e % 2;
					e = e / 2;
				}
				if(cnt <= k)
				{
					ans = (ans + SUM[i][j][k1]) % CONST;
				}
			}
		}
	}
	return ans;
}
signed main()
{
	int l, r, k;
	cin >> l >> r >> k;
	cout << (ans(r, k) - ans(l - 1, k) + CONST) % CONST;
	return 0;
}