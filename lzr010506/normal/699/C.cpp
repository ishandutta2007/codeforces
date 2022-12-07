#include <bits/stdc++.h>
using namespace std;
int n , a[100 + 2] , f[100 + 2][3];

inline int min(int a, int b)
{
	if(a < b) return a;
	else return b;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		f[i][0] = min( min(f[i - 1][0] , f[i - 1][1]) , f[i - 1][2] ) + 1;
		if(a[i] == 1 || a[i] == 3 )
			f[i][1] = min( f[i - 1][0] , f[i - 1][2] );
		else
			f[i][1] = 1 << 30;
		if( a[i] == 2 || a[i] == 3 )
			f[i][2] = min( f[i - 1][0] , f[i - 1][1] );
		else
			f[i][2] = 1 << 30;
	}
	cout << min( f[n][0] , min( f[n][1] , f[n][2] ) ) << endl;
	return 0;
}