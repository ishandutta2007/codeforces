#include<bits/stdc++.h>
using namespace std;
int test,na,nb,nc,a[111111],b[111111],c[111111],pa,pb,pc,cnt,x,y;
long long ans;
pair<int,int> d[333333];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&na,&nb,&nc);
		for (int i=1;i<=na;i++) scanf("%d",&a[i]);
		for (int i=1;i<=nb;i++) scanf("%d",&b[i]);
		for (int i=1;i<=nc;i++) scanf("%d",&c[i]);
		sort(a+1,a+na+1);
		sort(b+1,b+nb+1);
		sort(c+1,c+nc+1);cnt=0;
		for (int i=1;i<=na;i++) d[++cnt]=make_pair(a[i],1);
		for (int i=1;i<=nb;i++) d[++cnt]=make_pair(b[i],2);
		for (int i=1;i<=nc;i++) d[++cnt]=make_pair(c[i],3);
		sort(d+1,d+cnt+1);
		ans=4e18;
		for (int i=1;i<=cnt;i++)
		{
			if (d[i].second==1)
			{
				x=lower_bound(b+1,b+nb+1,d[i].first+1)-b-1;
				y=lower_bound(c+1,c+nc+1,d[i].first)-c;
				if (y<=nc && x>=1)
				{
					ans=min(ans,1ll*(d[i].first-b[x])*(d[i].first-b[x])+1ll*(d[i].first-c[y])*(d[i].first-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));
				}
				x=lower_bound(c+1,c+nc+1,d[i].first+1)-c-1;
				y=lower_bound(b+1,b+nb+1,d[i].first)-b;
				if (y<=nb && x>=1)
				{
					ans=min(ans,1ll*(d[i].first-c[x])*(d[i].first-c[x])+1ll*(d[i].first-b[y])*(d[i].first-b[y])+1ll*(c[x]-b[y])*(c[x]-b[y]));
				}
			}
			else if (d[i].second==2)
			{
				x=lower_bound(a+1,a+na+1,d[i].first+1)-a-1;
				y=lower_bound(c+1,c+nc+1,d[i].first)-c;
				if (y<=nc && x>=1)
				{
					ans=min(ans,1ll*(d[i].first-a[x])*(d[i].first-a[x])+1ll*(d[i].first-c[y])*(d[i].first-c[y])+1ll*(a[x]-c[y])*(a[x]-c[y]));
				}
				x=lower_bound(c+1,c+nc+1,d[i].first+1)-c-1;
				y=lower_bound(a+1,a+na+1,d[i].first)-a;
				if (y<=na && x>=1)
				{
					ans=min(ans,1ll*(d[i].first-c[x])*(d[i].first-c[x])+1ll*(d[i].first-a[y])*(d[i].first-a[y])+1ll*(c[x]-a[y])*(c[x]-a[y]));
				}
			}
			else
			{
				x=lower_bound(a+1,a+na+1,d[i].first+1)-a-1;
				y=lower_bound(b+1,b+nb+1,d[i].first)-b;
				if (y<=nb && x>=1)
				{
					ans=min(ans,1ll*(d[i].first-a[x])*(d[i].first-a[x])+1ll*(d[i].first-b[y])*(d[i].first-b[y])+1ll*(a[x]-b[y])*(a[x]-b[y]));
				}
				x=lower_bound(b+1,b+nb+1,d[i].first+1)-b-1;
				y=lower_bound(a+1,a+na+1,d[i].first)-a;
				if (y<=na && x>=1)
				{
					ans=min(ans,1ll*(d[i].first-b[x])*(d[i].first-b[x])+1ll*(d[i].first-a[y])*(d[i].first-a[y])+1ll*(b[x]-a[y])*(b[x]-a[y]));
				}
			}
		}
		printf("%lld\n",ans);
	}
}