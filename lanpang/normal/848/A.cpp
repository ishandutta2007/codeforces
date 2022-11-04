#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , h , a , c;

int main()
{
	int i , j;
	h = 'a';
	cin >> n;
	if (n == 0) cout << "a\n";
	while (n)
	{
		a = 1;
		c = 0;
		while (c <= n)
		{
			c += a;
			a++;
		}
		a--;
		c -= a;
		n -= c;
		while (a--)
			printf("%c",h);
		h++;
	}
	return 0;
}