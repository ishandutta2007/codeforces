#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m;
LL f[maxn];

int main()
{
	int i , j;
	cin >> n >> m;
	f[1] = 1;
	f[2] = 2;
	for (i = 3 ; i <= max(n,m) ; i++)
		f[i] = (f[i-1]+f[i-2])%mod;
	cout << (f[n]+f[m]-1)*2%mod << "\n";
	return 0;
}