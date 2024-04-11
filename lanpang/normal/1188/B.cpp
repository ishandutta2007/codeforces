#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n;
LL x , s , k , p;
map<LL,LL> mp;

int main()
{
	int i , j;
	cin >> n >> p >> k;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&x);
		s += mp[(x*x%p*x%p*x%p-k*x%p+p)%p]++;
	}
	cout << s << "\n";
	return 0;
}