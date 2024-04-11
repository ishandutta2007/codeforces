#include<bits/stdc++.h>

using namespace std;

bool hang[100005],lie[100005];
int h,l;
int i,j,k,m,n;
int x,y;
long long int ans;

int main()
{
	memset(hang,0,sizeof(hang));
	memset(lie,0,sizeof(lie));
	scanf("%d%d",&n,&m);
	ans=n;ans=ans*ans;h=l=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(!hang[x])
		{
			hang[x]=true;
			h++;
			ans-=(n-l);
		}
		if(!lie[y])
		{
			lie[y]=true;
			l++;
			ans-=(n-h);
		}
		printf("%lld",ans);
		if(i<m)printf(" ");
	}
	return 0;
}