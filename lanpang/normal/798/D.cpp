#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

struct mmp{
	long long  n , a , b;
}a[100001];

long long n , f[100001] , m;
long long aa , bb , sa , sb;

bool cmp(struct mmp x , struct mmp y)
{
	return x.a > y.a;
}

int main ()
{
	int i , j , k;
	cin >> n;
	m = n/2+1; 
	sa = 0;
	sb = 0;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i].a);
		sa += a[i].a;
		a[i].n = i;
	}
	for (i = 1 ; i <= n ; i++)	
	{
		scanf("%I64d",&a[i].b);
		sb += a[i].b;
	}
	sa = sa/2+1;
	sb = sb/2+1;
	sort(a+1,a+n+1,cmp);
	aa = a[1].a;
	bb = a[1].b;
	f[a[1].n] = 1;
	m = 1;
	for (i = 2 ; i < n ; i+=2)
	{
		if (aa >= sa && bb >= sb)
		{
			break;
		}
		else
		{
			if (a[i].b >= a[i+1].b)
			{
				f[a[i].n] = 1;
				aa += a[i].a;
				bb += a[i].b;
				m++;
			}
			else
			{
				f[a[i+1].n] = 1;
				aa += a[i+1].a;
				bb += a[i+1].b;
				m++;
			}
		}
	}
	if ((aa < sa || bb < sb) && n%2 == 0)
	{
		f[a[n].n] = 1;
		aa += a[n].a;
		bb += a[n].b;
		m++;
	}
	cout << m << "\n";
	k = 0;
	for (i = 1 ; i <= n ; i++)
	{
		if (f[i] > 0)
		{
			if (k == 0)
			{
				printf("%d",i);
				k++;
			}
			else
			{
				printf(" %d",i);
			}
		}
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}