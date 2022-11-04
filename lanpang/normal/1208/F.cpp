#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[maxn] , f[(1<<21)] , ans;

void ins(int x , int p)
{
	if (f[x] >= 2) return;
	f[x]++;
	for (int j = p ; j >= 0 ; j--)
		if (x&(1<<j)) ins(x-(1<<j),j-1);
}

int main()
{
	int i , j , x;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	ins(a[n],20);
	ins(a[n-1],20);
	for (i = n-2 ; i >= 1 ; i--)
	{
		x = 0;
		for (j = 20 ; j >= 0 ; j--)
		{
			if (a[i]&(1<<j)) continue;
			if (f[x|(1<<j)] >= 2) x |= (1<<j);
		}
		ans = max(ans,a[i]|x);
		ins(a[i],20);
	}
	cout << ans << "\n";
	return 0;
}