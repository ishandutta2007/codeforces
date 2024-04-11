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
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , q;
bitset<7010> b[7010] , c[7010] , a[maxn];

int main()
{
	int i , j , k , x , y , z;
	bitset<40> gg[40];
	for (i = 36 ; i >= 1 ; i--)
	{
		gg[i][i] = true;
		for (j = i*2 ; j <= 36 ; j += i)
			gg[i] ^= gg[j];
	}
	for (i = 7000 ; i >= 1 ; i--)
	{
		b[i][i] = true;
		for (j = i*2 ; j <= 7000 ; j += i)
			b[i] ^= b[j];
		for (j = i ; j <= 7000 ; j += i)
			c[j][i] = 1;
	}
	cin >> n >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d",&k);
		if (k == 1)
		{
			scanf("%d%d",&x,&y);
			a[x] = c[y];
		}
		if (k == 2)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[x] = a[y]^a[z];
		}
		if (k == 3)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[x] = a[y]&a[z];
		}
		if (k == 4)
		{
			scanf("%d%d",&x,&y);
			printf("%d",((a[x]&b[y]).count())%2);
		}
	}
	cout << "\n";
	return 0;
}