#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
using namespace std;
int pow(int a, int b)
{
	if(b == 1)
	{
		return a % MOD;
	}
	else if(b % 2 == 0)
	{
		int t = pow(a, b / 2);
		return (t * t) % MOD;
	}
	else
	{
		int t = pow(a, b / 2);
		return a * ((t * t) % MOD) % MOD;
	}
}
int A[N], prime[N];
vector <int> primes;
void pr()
{
	fill(prime + 2, prime + N, 1);
	A[1] = 1;
	for(int i = 2; i < N; i++)
	{
		if(prime[i])
		{
			primes.push_back(i);
			A[i] = -1;
		}
		for(int j = 0; j < primes.size(); j++)
		{
			int a = primes[j];
			if(i * a >= N)
			{
				break;
			}
			prime[i * a] = 0;
			if(i % a == 0)
			{
				A[i * a] = 0;
				break;
			}
			else
			{
				A[i * a] = A[i] * A[a];
			}
		}
	} 
}
main()
{
	pr();
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 2; i <= n; i++)
	{
		int f = n / i;
		ans -=(A[i] * f * pow(n - f, MOD - 2)) % MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}