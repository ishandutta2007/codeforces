#include<cstdio>
#include<iostream>
using std::min;
using std::max;
const int N=1e5+5,inf=1e9+5;
int n;
int l_min=-inf,l_max=inf,r_min=-inf,r_max=inf;
int a[N];
char b[N];
signed main()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",b+1);
	for(i=5;i<=n;i++)
		if(b[i-1]==b[i-2]&&b[i-1]==b[i-3]&&b[i-1]==b[i-4])
		{
			if(b[i-1]=='0')
			{
				if(b[i]!=b[i-1])
				{
					int now=-inf;
					for(j=i-4;j<=i;j++)
						now=max(now,a[j]);
					l_min=max(l_min,now+1);
				}
				else
				{
					int now=-inf;
					for(j=i-4;j<=i;j++)
						now=max(now,a[j]);
					l_max=min(l_max,now);
				}
			}
			else
			{
				if(b[i]!=b[i-1])
				{
					int now=inf;
					for(j=i-4;j<=i;j++)
						now=min(now,a[j]);
					r_max=min(r_max,now-1);
				}
				else
				{
					int now=inf;
					for(j=i-4;j<=i;j++)
						now=min(now,a[j]);
					r_min=max(r_min,now);
				}
			}
		}
	int l,r;
	l=l_min;
	while(l<-1000000000)
		l++;
	r=r_max;
	while(r>1000000000)
		r--;
	printf("%d %d\n",l,r);
	return 0;
}