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
const int maxn = 3e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , p , tr[maxn*4] , ans; 

void putin(int num , int l , int r , int x)
{
	if (l <= x && x <= r)
	{
		if (l == r) tr[num] = 1;
		else
		{
			int nn = num*2 , mm = (l+r)/2;
			putin(nn,l,mm,x);
			putin(nn+1,mm+1,r,x);
			tr[num] = tr[nn]+tr[nn+1];
		}
	}
	else return;
}

int getout(int num , int l , int r , int x , int y)
{
	if (l > y || x > r) return 0;
	else
	{
		if (x <= l && r <= y) return tr[num];
		else
		{
			int nn = num*2 , mm = (l+r)/2;
			return getout(nn,l,mm,x,y)+getout(nn+1,mm+1,r,x,y);
		}
	}
}

int main ()
{
	int i , j , nn;
	ans = 1;
	cin >> n;
	nn = n;
	for (i = 1 ; i <= n ; i++)
	{
		printf("%d ",ans);
		scanf("%d",&p);
		putin(1,1,n,p);
		while (getout(1,1,n,nn,nn) == 1) nn--;
		ans = getout(1,1,n,1,nn)+1;
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}