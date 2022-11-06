#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,t,ans,cnt;
int p[N],bk[N];
inline void solve()
{
	int l,r,mid,lst;
	register int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		p[i]=i;
	random_shuffle(p+1,p+n+1);
	memset(bk+1,0,sizeof(int)*n);cnt=0;
	for(i=1;i<=n;i++)
	{
		if(i<n-1)
		{
			printf("? %d %d\n",1,n-i);
			printf("%d\n",p[i]);
			for(j=i+1;j<=n;j++)
				printf("%d ",p[j]);
			putchar('\n');fflush(stdout);
			scanf("%d",&ans);
		}
		else
			ans=1;
		if(ans)
		{
			for(j=i+1;j<n;j++)
			{
				lst=ans;
				printf("? 1 %d\n%d\n",n-j,p[i]);
				for(k=j+1;k<=n;k++)
					printf("%d ",p[k]);
				putchar('\n');
				fflush(stdout);
				scanf("%d",&ans);
				if(!(ans-lst))
					cnt++,bk[p[j]]=1;
			}
			if(!ans)
				cnt++,bk[p[n]]=1;
			if(i>1)
			{
				printf("? %d 1\n",i-1);
				for(j=1;j<=i-1;j++)
					printf("%d ",p[j]);
				putchar('\n');
				printf("%d\n",p[i]);
				fflush(stdout);
				scanf("%d",&ans);
				if(ans)
				{
					l=1;r=i-1;
					while(l<r)
					{
						mid=(l+r)/2;
						printf("? %d 1\n",mid-l+1);
						for(j=l;j<=mid;j++)
							printf("%d ",p[j]);
						putchar('\n');
						printf("%d\n",p[i]);
						fflush(stdout);
						scanf("%d",&ans);
						if(ans)
							r=mid;
						else
							l=mid+1;
					}
					for(j=1;j<=i-1;j++)
						if(j!=l)
							cnt++,bk[p[j]]=1;
				}
				else
				{
					for(j=1;j<=i-1;j++)
						cnt++,bk[p[j]]=1;
				}
			}
			break;
		}
	}
	printf("! %d ",cnt);
	for(i=1;i<=n;i++)
		if(bk[i])
			printf("%d ",i);
	putchar('\n');fflush(stdout);
	return;
}
signed main()
{
	srand(312410);
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}