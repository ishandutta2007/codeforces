#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[1111],t,l,r,x;
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	t=c/2;l=1;r=n;
	while(l<=r)
	{
		scanf("%d",&x);
		if (x<=t)
		{
			if (l==1 || a[l-1]<=x)
			{
				printf("%d\n",l);
				fflush(stdout);
				a[l]=x;
				l++;
			}
			else
			{
				for (int i=1;i<l;i++)
				{
					if (a[i]>x)
					{
						printf("%d\n",i);
						fflush(stdout);
						a[i]=x;
						break;
					}
				}
			}
		}
		else
		{
			if (r==n || a[r+1]>=x) 
			{
				printf("%d\n",r);
				fflush(stdout);
				a[r]=x;
				r--;
			}
			else
			{
				for (int i=n;i>r;i--)
				{
					if (a[i]<x)
					{
						printf("%d\n",i);
						fflush(stdout);
						a[i]=x;
						break;
					}
				}
			}
		}
	}
	return 0;
}