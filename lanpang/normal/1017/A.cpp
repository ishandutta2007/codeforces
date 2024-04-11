#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
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
typedef pair <int,int> II;
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x ,id;
}p[maxn];
int n;
bool cmp(mmp x , mmp y)
{
	if (x.x == y.x) return x.id < y.id;
	else return x.x > y.x;
}

int main()
{
	int i , a , b , c , d;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a >> b >> c >> d;
		p[i].x = a+b+c+d;
		p[i].id = i;
	}
	sort(p+1,p+n+1,cmp);
	for (i = 1 ; i <= n ; i++)
	{
		if (p[i].id == 1)
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}