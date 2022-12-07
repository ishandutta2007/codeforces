#include<bits/stdc++.h>

using namespace std;

struct hi
{
	int x,y;
}a[105];

int i,j,k,l,m,n;

void ss(int x,int y)
{
	int ii,jj,s;
	struct hi o;
	ii=x;jj=y;
	s=a[(x+y)/2].x;
	while(ii<=jj)
	{
		while(a[ii].x<s)ii++;
		while(a[jj].x>s)jj--;
		if(ii<=jj)
		{
			o=a[ii];a[ii]=a[jj];a[jj]=o;
			ii++;jj--;
		}
	}
	if(x<jj)ss(x,jj);
	if(ii<y)ss(ii,y);
}

int min(int x,int y)
{
	return x<y?x:y;
}

int max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].y=i;
	}
	ss(1,n);
	for(i=1;i<=n/2;i++)printf("%d %d\n",min(a[i].y,a[n+1-i].y),max(a[i].y,a[n+1-i].y));
	return 0;
}