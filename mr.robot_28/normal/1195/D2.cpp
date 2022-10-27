#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long CONST = 998244353;
int pow1(int a, int n)
{
	if(n == 0)
	{
		return 1 % CONST;
	}
	else if(n % 2 == 1)
	{
		int k = pow1(a, n / 2);
		k = (k * k) % CONST;
		return ( k * a) % CONST;
	}
	else
	{
		int k = pow1(a, n / 2);
		k = (k * k) % CONST;
		return k;
	}
}
signed main()
{
	int n;
	cin >> n;
	int sum = 0;
	vector <int> A(n), cnt(11), CNT(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		int k = A[i], c = 0;
		while(k > 0)
		{
			c++;
			k = k / 10;
		}
		CNT[i] = c;
		cnt[c]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		vector <int> B;
		int k = A[i], c = 1;
		while(k > 0)
		{
			B.push_back(k % 10);
			k = k / 10;
		}
		for(int j = 1; j <= 10; j++)
		{
			int c = 1;
			int sum = 0;
			for(int p = 0; p < B.size(); p++)
			{
				sum = (sum + (B[p] * pow1(10, c)) % CONST) % CONST;
				if(p + 1 >= j)
				{
					c++;
				}
				else
				{
					c += 2;
				}
			}
			ans = (ans + cnt[j] * sum % CONST) % CONST;
		}
		for(int j = 1; j <= 10; j++)
		{
			int c = 0;
			int sum = 0;
			for(int p = 0; p < B.size(); p++)
			{
				sum = (sum + (B[p] * pow1(10, c)) % CONST) % CONST;
				if(p + 1 > j)
				{
					c++;
				}
				else
				{
					c += 2;
				}
			}
			ans = (ans + cnt[j] * sum % CONST) % CONST;
		}
	}
	cout << ans;
	return 0;
}