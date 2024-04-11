#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , l , ans;
char a[10];

struct mmp{
	int x , y;
}f[10];

bool cmp1(mmp x , mmp y)
{
	if (x.y == y.y) return x.x > y.x;
	else return x.y < y.y;
}

bool cmp(mmp x , mmp y)
{
	return x.x > y.x;
}

int main ()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%s",&a);
		l = strlen(a);
		k = 1;
		for (j = l-1 ; j >= 0 ; j--)
		{
			f[a[j]-'a'].x += k;
			k *= 10;
			if (j == 0) f[a[j]-'a'].y = 1;
		}
	}
	sort(f,f+10,cmp1);
	sort(f+1,f+10,cmp);
	for (i = 1 ; i <= 9 ; i++)
	{
		ans += f[i].x*i;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}