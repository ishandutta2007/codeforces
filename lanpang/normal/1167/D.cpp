#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int n , b[maxn] , ma , d , q[maxn] , tp;
char a[maxn];

int main()
{
	int i , j;
	cin >> n >> a+1;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == '(') 
		{
			q[++tp] = i;
			d++;
			ma = max(ma,d);
		}
		else
		{
			b[q[tp]] = d;
			tp--;
			b[i] = d;
			d--;
		}
	}
	for (i = 1 ; i <= n ; i++)
		if (b[i] > ma/2) printf("0");
		else printf("1");
	cout << "\n";
	return 0;
}