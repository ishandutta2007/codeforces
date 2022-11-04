#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , a , b , n;

int main()
{
	int i , j;
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> n;
		n %= 3;
		if (n == 0) cout << a << "\n";
		else if (n == 1) cout << b << "\n";
		else cout << (a^b) << "\n";
	}
	return 0;
}