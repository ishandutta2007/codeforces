#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , a[maxn] , b[maxn] , ans;
map<int,int> mpa , mpb;

void jisuan(int dis)
{
	mpa.clear();
	mpb.clear();
	int i , j;
	for (i = n ; i >= 1 ; i--)
		mpa[a[i]%(dis*2)]++;
	for (i = m ; i >= 1 ; i--)
		mpb[b[i]%(dis*2)]++;
	for (i = n ; i >= 1 ; i--)
	{
		j = (a[i]%(dis*2)+dis)%(dis*2);
		ans = max(ans,mpa[a[i]%(dis*2)]+mpb[j]);
	}
	for (i = m ; i >= 1 ; i--)
	{
		j = (b[i]%(dis*2)+dis)%(dis*2);
		ans = max(ans,mpb[b[i]%(dis*2)]+mpa[j]);
	}
}

int main()
{
	int i;
	cin >> n >> i;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	cin >> m >> i;
	for (i = 1 ; i <= m ; i++)
		scanf("%d",&b[i]);
	for (i = 0 ; i < 30 ; i++)
		jisuan((1<<i));
	cout << max(ans,2) << "\n";
	return 0;
}