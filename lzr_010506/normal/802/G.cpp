#include <bits/stdc++.h>
using namespace std;
int f[1010][10];
int main()
{
	string a, b;
	cin >> a;
	b = "heidi";
	int n = a.size();
	int m = b.size();
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
		{
			if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	if(f[n - 1][m - 1] == 5) cout << "YES";
	else cout << "NO";

	return 0;
}