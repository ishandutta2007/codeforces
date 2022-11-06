#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 110
int a[N][N];
int main()
{
	int n, k;
	cin >> n >> k;

	if(n * n < k)
	{
		cout << -1 << endl; return 0;
	}
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
		{
			if(!k) break;
			if(i == j) a[i][j] = 1, k --;
			else if(k == 1) a[i + 1][i + 1] = 1, k --;
			else a[i][j] = a[j][i] = 1, k -= 2;
		}
	for(int i = 1; i <= n; i ++, puts(""))
		for(int j = 1; j <= n; j ++)
			cout << a[i][j] << " ";

	return 0;
}