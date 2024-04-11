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
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		int k = A[i];
		int a = 0, cnt = 0;
		while(A[i] > 0){
			a = (a + (A[i] % 10) * pow1(10, cnt * 2 + 1) % CONST) % CONST;
			cnt++;
			A[i] = A[i] / 10;
		}
		sum = (sum + a * n % CONST) % CONST;
		a = 0;
		cnt = 0;
		while(k > 0)
		{
			a = (a + (k % 10) * pow1(10, cnt * 2) % CONST) % CONST;
			cnt++;
			k = k / 10;
		}
		sum = (sum + a * n % CONST) % CONST;
	}
	cout << sum;
	return 0;
}