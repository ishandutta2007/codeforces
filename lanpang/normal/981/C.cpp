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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int id , du;
}a[maxn];
int n , x , y , i , p , cnt;
vector <int> v[maxn];
bool cmp(mmp x , mmp y)
{
	return x.du > y.du;
}

int main()
{
	cin >> n;
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		a[y].du++;
		a[x].du++;
	}
	for (i = 1 ; i <= n ; i++) a[i].id = i;
	sort(a+1,a+n+1,cmp);
	if (a[2].du > 2)
	{
		cout << "No\n";
		return 0;
	}
	for (i = n ; i >= 2 ; i--)
	{
		if (a[i].du == 1) cnt++;
		else break;
	}
	cout << "Yes\n" << cnt << "\n";
	for (i = n ; i >= 2 ; i--)
	{
		if (a[i].du == 1) printf("%d %d\n",a[1].id,a[i].id);
		else break;
	}
	return 0;
}