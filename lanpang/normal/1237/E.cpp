#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , x , y , f[maxn];

int main()
{
	int i , j;
	x = 1;
	y = 2;
	while (x <= 1000000)
	{
		f[x] = f[x+1] = 1;
		x = x*2+y;
		y = 3-y;
	}
	cin >> n;
	cout << f[n] << "\n";
	return 0;
}