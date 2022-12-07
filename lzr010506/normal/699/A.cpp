#include <bits/stdc++.h>
#define N 200010
using namespace std;
set <int> mp[2];
int n, a[N], ans = 2000000000;
char s[N];

inline int min(int a, int b)
{
	if(a < b) return a;
	else return b;
}

int main()
{
	cin >> n;
	scanf("%s",s + 1);
	for(register int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	for(register int i = 1; i <= n; i ++)
		if( s[i] == 'L' )
			mp[0].insert( a[i] );
		else
			mp[1].insert( a[i] );
	for(register int i = 1; i <= n; i ++)
		if(s[i] == 'L')
		{
			set <int> :: iterator x = mp[1].lower_bound( a[i] );
			if(x != mp[1].begin())
			{
				x --;
				ans = min(ans, a[i] - *x);
			}
		}
	if(ans == 2000000000) ans = -2;
	cout << ans / 2 << endl;
	return 0;
}