#include <bits/stdc++.h>
#define N 1024
using namespace std;

int n , m , l[N][N] , r[N][N] , tot;
char a[N][N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf( "%s" , a[i] + 1 );
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			r[i][j] = r[i][j - 1] + ( a[i][j] == '*' );
	for(int j = 1; j <= m; j ++)
		for(int i = 1; i <= n; i ++)
			l[i][j] = l[i - 1][j] + ( a[i][j] == '*' );
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			tot += a[i][j] == '*';
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if( l[n][j] + r[i][m] - ( a[i][j] == '*' ) == tot )
			{
				cout << "YES" << endl << i << " " << j << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}