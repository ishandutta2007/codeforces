#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n , m , s;

int main()
{
	int i , j;
	cin >> n >> m;
	s = 1;
	for (i = 1 ; i <= n+m ; i++)
		s = s*2%mod;
	cout << s << "\n";
	return 0;
}