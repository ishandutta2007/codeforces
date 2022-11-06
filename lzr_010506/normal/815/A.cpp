#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int b[N][N], a[N][N], row[N], lie[N];
int main() 
{
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x ++)
		for (int y = 0; y < m; y ++) 
		{
			cin >> a[x][y];	
			b[x][y] = a[x][y];
		}
	int mn = 1e9, px = -1, py = -1;
	for (int x = 0; x < n; x ++) 
		for (int y = 0; y < m; y ++)
			if (a[x][y] < mn) 
			{
				mn = a[x][y];
				px = x;
				py = y;
			}
	if (n < m) 
		for (int j = 0; j < n; j ++) row[j] += mn;	
	else 
		for (int j = 0; j < m; j ++) lie[j] += mn;
	
	for (int x = 0; x < n; x ++)
		for (int y = 0; y < m; y ++)
			a[x][y] -= mn;
	for (int x = 0; x < n; x ++)
		row[x] += (a[x][py] - a[px][py]);
	
	for (int y = 0; y < m; y ++) 
		lie[y] += (a[px][y] - a[px][py]);
	
	for (int x = 0; x < n; x ++)
		for (int y = 0; y < m; y ++)
			if (row[x] + lie[y] != b[x][y]) 
			{
				cout << -1 << endl;
				return 0;
			}
	int all = 0;
	for (int x = 0; x < n; x ++) all += row[x];
	for (int y = 0; y < m; y ++) all += lie[y];
	cout << all << endl;
	for (int x = 0; x < n; x ++)
		while (row[x] --)
			cout << "row " << x + 1 << '\n';
	for (int y = 0; y < m; y ++) 
		while (lie[y] --) 
			cout << "col " << y + 1 << '\n';
	return 0;
}