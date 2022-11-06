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

struct mmp{
	int l , r;
	long long c;
}a[200001] , b[200001];

long long n , m , pp , f[200001] , mi=4000000001;

bool cmp1(struct mmp x , struct mmp y)
{
	return x.l < y.l;
}

bool cmp2(struct mmp x , struct mmp y)
{
	return x.r < y.r;
}

int main ()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d%I64d%I64d",&a[i].l,&a[i].r,&a[i].c);
		b[i].l = a[i].l;
		b[i].r = a[i].r;
		b[i].c = a[i].c;
	}
	for (i = 0 ; i <= 200000 ; i++)
	{
		f[i] = 2000000001;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	pp = 1;
	for (i = 1 ; i <= n ; i++)
	{
		while(b[pp].r < a[i].l)
		{
			if (b[pp].c < f[b[pp].r-b[pp].l+1])
			{
				f[b[pp].r-b[pp].l+1] = b[pp].c;
			}
			pp++;
		}
		if (m-a[i].r+a[i].l-1 >= 0 && f[m-a[i].r+a[i].l-1] + a[i].c < mi)
		{
			mi = f[m-a[i].r+a[i].l-1] + a[i].c;
		}
	}
	if (mi > 2000000000)
	    cout << "-1\n";
	else    
		cout << mi << "\n";
	//system("PAUSE");
	return 0;
}