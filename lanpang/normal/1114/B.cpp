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
const LL mod = 1e9+7;

int n , m , k , b[maxn] , cnt;
LL s;
struct mmp{
	int x , y;
	bool operator < (const mmp &op) const{
		return x > op.x;
	}
}a[maxn];

int main()
{
	int i , j;
	cin >> n >> m >> k;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i].x);
		a[i].y = i;
	}
	sort(a+1,a+n+1);
	for (i = 1 ; i <= m*k ; i++)
	{
		s += a[i].x;
		b[a[i].y] = 1;
	}
	cout << s << "\n";
	for (i = 1 ; i <= n ; i++)
	{
		cnt += b[i];
		if (b[i] == 1 && cnt%m == 0)
		{
			if (cnt == m*k) break;
			printf("%d ",i);
		}
	} 
	cout << "\n";
	return 0;
}