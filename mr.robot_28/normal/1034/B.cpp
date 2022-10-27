#include<bits/stdc++.h>
using namespace std;
#define int long long
int max(int a, int b)
{
	if(a >= b)
	{
		return a;
	}
	return b;
}
signed main() {
	int n, m;
	cin >> n >> m;
	if(n > m)
	{
		swap(n, m);
	}
	if(n == 1)
	{
		cout << m / 6 * 6 + max(0, m % 6 - 3) * 2;
	}
	else if(n == 2)
	{
		if(m == 2)
		{
			cout << 0;
		}
		else if(m == 3)
		{
			cout << 4;
		}
		else if(m == 7)
		{
			cout << 12;
		}
		else
		{
			cout << m * 2;
		}
	}
	else
	{
		cout << m * n / 2 * 2;
	}
    return 0;
}