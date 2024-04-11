#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int maxn = 1e7 + 6;
bool bad[maxn];
int prime[maxn];
int phi[maxn];
int number_of_prime_divisors[maxn];
int pref[maxn];
int number_of_bad = 0;
void precalc()
{
	for(int i = 1; i <= n; i++)
	{
		phi[i] = i;
	}
	for(int i = 2; i <= n; i++)
	{
		if(prime[i]){
			continue;
		}
		for(int j = i; j <= n; j += i)
		{
			if(!prime[j])
			{
				prime[j] = i;
			}
			phi[j] /= i;
			phi[j] *= i - 1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || prime[i] ==i && i * 2 > n)
		{
			bad[i] = true;
			number_of_bad++;
		}
	}
	for(int i = 2; i <= n; i++)
	{
		if(prime[i] == i)
		{
			number_of_prime_divisors[i] = 1;
		}
		else if(prime[i / prime[i]] == prime[i])
		{
			number_of_prime_divisors[i] = number_of_prime_divisors[i / prime[i]];
		}
		else
		{
			number_of_prime_divisors[i] = number_of_prime_divisors[i / prime[i]] + 1;
		}
	}
}
int funct1(){
	int ans = 0;
	for(int i = 2; i <= n; i++)
	{
		if(!bad[i])
		{
			ans += i - 1 - phi[i];
		}
	}
	return ans;
}
int funct2()
{
	int ans = 0;
	int pr1 = 1;
	for(int i = 2; i <= n; i++)
	{
		if(prime[i] == i)
		{
			pr1++;
		}
		else
		{
			ans -= pr1;
			ans += number_of_prime_divisors[i];
			ans += phi[i];
		}
	}
	for(int i = 1; i <= n; i++){
		if(!bad[i]){
			pref[prime[i]]++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		pref[i] += pref[i - 1];
	}
	for(int i = 2; i <= n; i++)
	{
		if(prime[i] != i || bad[i])
		{
			continue;
		}
		ans += pref[n / i];
		for(int j = i; j <= n; j += i)
		{
			if(prime[j] <= n / i)
			{
				ans--;
			}
		}
	}
	for(int i = 2; i <= n; i++)
	{
		int a = prime[i];
		int b = i / a;
		if(b != 1 && prime[b] == b && a != b)
		{
			ans--;
		}
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	precalc();
	int cnt1 = funct1();
	int cnt2 = funct2();
	int cnt3 = (n - number_of_bad) * (n - number_of_bad - 1) / 2 - cnt1 - cnt2;
	cout << cnt1 + 2 * cnt2 + 3 * cnt3;
	return 0;
}