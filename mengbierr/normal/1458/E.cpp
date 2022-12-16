#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m;
map<pii,int> mp;
map<int,int> vis;
struct point
{
	int x,y;
}p[1000005],q[1000005];
bool cmp(const point &x,const point &y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool cmp1(const point &x,const point &y)
{
	if(x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}
int tot,pla[1000005],a[1000005],b[1000005];
int find(int x)
{
	int ans=tot,l=1,r=tot;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(pla[mid]<=x)
		{
			
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		mp[pii(p[i].x,p[i].y)]=1;
		q[i]=p[i];
	}
	sort(q+1,q+n+1,cmp1);
	sort(p+1,p+n+1,cmp);
	pla[++tot]=-1;
	a[tot]=-1;b[tot]=-1;
	p[0].x=-1;
	int now=1;
	for(int i=1;i<=n;i++)
	{
		
		if(p[i].x==p[i-1].x)
		{
			vis[p[i].y]=1;
			continue;
		}
		
		while(now<=n)
		{
			//cout<<b[tot]<<" "<<p[i].x<<" "<<pla[tot]<<endl;
			if(b[tot]>=q[now].y&&now<=n)
			{
				//cout<<"???"<<i<<" "<<now<<endl;
				now++;continue;
			}
			else if(q[now].y<=b[tot]+(p[i].x-pla[tot]))
			{
				if(q[now].x>=p[i].x)
				{
					now++;continue;
				}
				//cout<<"!!!"<<now<<endl;
				
				tot++;
				pla[tot]=q[now].y-b[tot-1]+pla[tot-1];
				int ans=q[now].y;
				while(now<=n)
				{
					if(q[now].y==ans) now++;
					else if(q[now].y==ans+1&&q[now].x<pla[tot]) ans++,now++;
					else break;
				}
				a[tot]=b[tot]=ans+1;
			}
			else break;
		}
		tot++;
		pla[tot]=p[i].x;
		a[tot]=b[tot-1]+(p[i].x-pla[tot-1]);
		//cout<<a[tot]<<" ";
		while(vis[a[tot]]) a[tot]++;
		a[tot]=min(a[tot],p[i].y);
		
		b[tot]=max(b[tot-1]+(p[i].x-pla[tot-1]-1),a[tot]);
		vis[p[i].y]=1;
		//cout<<b[tot]<<" ";
	}
	while(now<=n)
	{
		if(b[tot]>=q[now].y)
		{
			now++;continue;
		}
		tot++;
		pla[tot]=q[now].y-b[tot-1]+pla[tot-1];
		int ans=q[now].y;
		while(now<=n)
		{
			if(q[now].y==ans) now++;
			else if(q[now].y==ans+1) ans++,now++;
			else break;
		}
		a[tot]=ans+1;
		b[tot]=a[tot];
	}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int l=find(x);
		if(mp[pii(x,y)]==1)
		{
			puts("LOSE");
			continue;
		}
		if(x==pla[l])
		{
			if(y==a[l]) puts("LOSE");
			else puts("WIN");
		}
		else
		{
			int tmp=b[l]+(x-pla[l]);
			//cout<<tmp<<" "<<pla[l]<<endl;
			if(y==tmp) puts("LOSE");
			else puts("WIN");
		}
	}
}