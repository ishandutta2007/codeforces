#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , k , x;

int main()
{
	int i , j;
	cin >> n >> k;
	x = (n-k)/2+1;
	for (i = 1 ; i <= n ; i++)
		printf("%c",(i%x == 0 ? '1' : '0'));
	cout << "\n";
	return 0;
}