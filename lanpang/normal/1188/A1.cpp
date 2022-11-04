#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , du[maxn];

int main()
{
	int i , j , x , y;
	cin >> n;
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		du[x]++;
		du[y]++;
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (du[i] == 2)
		{
			cout << "NO\n";
			break;
		}
	}
	if (i > n) cout << "YES\n";
	return 0;
}