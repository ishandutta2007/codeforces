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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int l , r , s;
}tr[maxn*20];
int top , root[maxn] , n , m , ans;

void putin(int &num , int l , int r , int x , int y)
{
	if (x < l || x > r) return;
	if (num == 0) num = ++top;
	if (l == r)
	{
		tr[num].s = max(tr[num].s,y);
		return; 
	}
	putin(tr[num].l,l,(l+r)/2,x,y);
	putin(tr[num].r,(l+r)/2+1,r,x,y);
	tr[num].s = max(tr[tr[num].l].s,tr[tr[num].r].s);
}

int getout(int num , int l , int r , int x , int y)
{
	if (x > r || l > y || num == 0) return 0;
	if (x <= l && r <= y) return tr[num].s;
	return max(getout(tr[num].l,l,(l+r)/2,x,y),getout(tr[num].r,(l+r)/2+1,r,x,y));
}

int main()
{
	int i , j , x , y , z;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		j = getout(root[x],0,100000,0,z-1)+1;
		ans = max(ans,j);
		putin(root[y],0,100000,z,j);
	}
	cout << ans << "\n";
	return 0;
}