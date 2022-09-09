#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
const int base=10;
struct BigInt 
{
	int a[1000];
	int l;
	BigInt () {memset (a, 0, sizeof(a));}
	BigInt (int x)
	{
		
		memset (a, 0, 1000); 
		l=0;
		a[0]=x;
		for (l=0; a[l]!=0; ++l)
		{
			a[l+1]=a[l]/base;
			a[l]%=base;
		}
	}
	void print ()
	{
		if (l==0)
			printf ("0");
		int i=l;
		for (i=l-1; i>=0; i--)
			printf ("%d", a[i]);
	}
	BigInt operator+(BigInt b)
	{
		BigInt res;
		int i;
		for (i=0; i<=l || i<=b.l; i++)
		{
			res.a[i+1]=(res.a[i]+a[i]+b.a[i])/base;
			res.a[i]=(res.a[i]+a[i]+b.a[i])%base;
		}
		for (i=l+b.l; i>=0; i--)
		{
			if (res.a[i]!=0)
				break;
		}
		res.l=i+1;
		return res;
	}
	void scan()
	{
		int i=0;
		char c=2;
		while (c!='\n' && c!=' ')
		{
			c=getchar ();
			if (c=='\n' || c==' ')
				break;
			a[i]=c-48;
			i++;
		}
		reverse (a, a+i);
		l=i;
	}
	BigInt operator*(int b)
	{
		BigInt res;
		int i;
		for(i=0;i<=l+1;i++)
		{
			res.a[i]+=a[i]*b;
			res.a[i+1]=(res.a[i])/base;
			res.a[i]%=base;
		}
		for (i=l+2; i>=0; i--)
		{
			if (res.a[i]!=0)
				break;
		}
		res.l=i+1;
		return res;
	}
};
int a[1000];
int main ()
{
int n, i, j, k=0, q=0, p,m;
memset (a, 0, sizeof (a));
scanf("%d%d", &n, &m);
for(i=1;i<=m;i++)
{
	scanf("%d%d", &p, &q);
	for(j=p;j<=q;j++)
		a[j]++;
}
for(i=1;i<=n;i++)
{
	if(a[i]!=1)
	{
		printf("%d %d", i, a[i]);
		return 0;
	}
}
printf("OK");
return 0;
}