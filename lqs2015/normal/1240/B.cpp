#include<bits/stdc++.h>
#define Accepted 0 
using namespace std;
int test,dp[333333],l[333333],r[333333],n,a[333333],ans,cnt,bit[666666],sz,pos,mx,nxt[333333];
pair<int,int> b[333333];
void update(int p,int x)
{
	while(p<=sz)
	{
		bit[p]=max(bit[p],x);
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res=max(res,bit[p]);
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for (int i=1;i<=n;i++)
		{
			l[i]=1e9;r[i]=-1e9;
		}
		for (int i=1;i<=n;i++)
		{
			l[a[i]]=min(l[a[i]],i);
			r[a[i]]=max(r[a[i]],i);
		}
		l[n+1]=0;nxt[n+1]=n+1;
		for (int i=1;i<=n;i++)
		{
			if (l[i]<1e8) ans++;
		}
		for (int i=n;i>=1;i--)
		{
			if (l[i+1]<1e8) nxt[i]=i+1;
			else nxt[i]=nxt[i+1];
		}
		mx=0;cnt=1;
		for (int i=1;i<=n;i++)
		{
			if (l[i]<1e8) 
			{
				pos=i;
				break;
			}
		}
		for (int i=pos;i<=n;i=nxt[i])
		{
			if (r[i]<l[nxt[i]]) cnt++;
			else
			{
				mx=max(mx,cnt);
				cnt=1;
			}
		}
		mx=max(mx,cnt);
		printf("%d\n",ans-mx);
	}
	return Accepted;
}