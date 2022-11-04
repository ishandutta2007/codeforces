#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int t , n , p;
char a[maxn];

int main()
{
	int i , j;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> a;
		for (i = 0 ; i < n ; i++)
			if (a[i] == '8') break;
		if (n-i >= 11) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}