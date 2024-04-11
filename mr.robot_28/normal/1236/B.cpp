#include <bits/stdc++.h>

using namespace std;
#define int long long
const int CONST = 1e9 + 7;
int pow1(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 1)
	{
		int k = pow1(a, b / 2);
		k = (k * k) % CONST;
		return k * a % CONST;
	}
	else
	{
		int k = pow1(a, b / 2);
		return (k * k) % CONST;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int t = pow1(2, m) - 1;
	cout << pow1(t, n);
    return 0;
}