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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int i , t;
}mp , b[maxn];

int n , t;
vector <mmp> a[maxn];

bool cmp(mmp x , mmp y)
{
	return x.t < y.t;
}

int solve(int x)
{
	int i , j , top=0 , sum=0;
	for (i = x ; i <= n ; i++)
	{
		for (j = 0 ; j < a[i].size() ; j++)
		{
			top++;
			b[top] = a[i][j]; 
		}
	}
	if (top < x) return 0;
	sort(b+1,b+top+1,cmp);
	for (i = 1 ; i <= x ; i++)
	{
		sum += b[i].t;
	}
	return sum <= t;
}

void erfen()
{
	int l=0 , r=n+1 , m , i;
	while (l <= r)
	{
		m = (l+r)/2;
		if (solve(m)) l = m+1;
		else r = m-1;
	}
	l--;
	cout << l << "\n" << l << "\n";
	solve(l);
	for (i = 1 ; i <= l ; i++)
	{
		printf("%d ",b[i].i);
	}
	cout << "\n";
}


int main()
{
	LL i , j , x , y;
	cin >> n >> t;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&x,&y);
		mp.i = i;
		mp.t = y;
		a[x].push_back(mp);
	}
	erfen();
	return 0;
}