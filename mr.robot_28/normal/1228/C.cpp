#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
int pow1(int a, int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n == 1)
	{
		return a % CONST;
	}
	else if(n % 2 == 0)
	{
		int g = pow1(a, n / 2);
		return (g * g) % CONST;
	}
	else
	{
		int g = pow1(a, n / 2);
		g = (g * g) % CONST;
		return (a * g) % CONST;
	}
}
signed main()
{
	int x, n;
	cin >> x >> n;
	vector <int> A;
	int x1 = x;
	for(int i = 2; i <= sqrt(x); i++)
	{
		if(x1 % i == 0)
		{
			A.push_back(i);
			while(x1 % i == 0)
			{
				x1= x1 / i;
			}
		}
	}
	if(x1 != 1)
	{
		A.push_back(x1);
	}
	int ans = 1;
	for(int i = 0; i < A.size(); i++)
	{
		int j = A[i];
		while(n >= j)
		{
			ans = (ans * pow1(A[i], n / j)) % CONST;
			if(n / j < A[i])
			{
				break;
			}
			j = j * A[i];
		}
	}
	cout << ans;
	return 0;
}