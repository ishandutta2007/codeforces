#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, q;
ll a[100000 + 2] , m;
int cmp(int a, int b)
{
	return a < b;
}
int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++ ) cin >> a[i];
	sort( a + 1 , a + n + 1, cmp);
	cin >> q;
	while( q-- )
	{
		cin >> m;
		int l = 1 , r = n , mid , ans = -1;
		while( l <= r )
		{
			mid = ( l + r ) >> 1;
			if( a[ mid ] <= m ) l = mid + 1 , ans = mid;
			else r = mid - 1;
		}
		if(ans < 0) cout << 0 <<endl;
		else cout << ans << endl;
	}
	return 0;
}