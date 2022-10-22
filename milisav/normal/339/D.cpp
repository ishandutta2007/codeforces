#include <iostream>
#include <cstdio>
#include <cmath>
int bit[10000000];
bool dr[10000000];
int n,nr,m;
int p,b;
int l=131072;
int main()
{
	scanf("%d %d",&nr,&m);
	n=pow(2,nr);
	l=n;
	bool f=true;
	for(int i=l;i<l+n;i++) scanf("%d",&bit[i]);
	if(nr%2==0) f=false;
	else f=true;
	int k=2;
	for(int i=1;i<l*2;i++)
	{
		if(i>=k)
		{
			f=!f;
			k=k*2;
		}
		dr[i]=f;
	}
	for(int i=l-1;i>0;i--)
	{
		if(dr[i]) bit[i]=bit[2*i]|bit[2*i+1];
		else bit[i]=bit[2*i]^bit[2*i+1];
	}
	int i;
	for(int j=0;j<m;j++)
	{
		scanf("%d %d",&p,&b);
		i=p-1+l;
		bit[i]=b;
		i=i/2;
		while(i>0)
		{
			if(dr[i]) bit[i]=bit[2*i]|bit[2*i+1];
			else bit[i]=bit[2*i]^bit[2*i+1];
			i=i/2;
		}
		printf("%d\n",bit[1]);
	}
	return 0;
}