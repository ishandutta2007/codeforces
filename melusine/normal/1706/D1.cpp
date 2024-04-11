#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
priority_queue<pair<int,int> >pq;
int qz[200005];
int now[200005];
struct tree
{
	int l,r,maxn;
}a[800004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r)
	{
		a[k].maxn=qz[l];
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	a[k].maxn=max(a[k<<1].maxn,a[k<<1|1].maxn);
}
void change(int x,int k,int y)
{
	if(a[k].l==a[k].r)
	{
		a[k].maxn=y;
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1,y);
	else change(x,k<<1|1,y);
	a[k].maxn=max(a[k<<1].maxn,a[k<<1|1].maxn);
}
int query(int l,int r,int k)
{
	if(a[k].l>r||a[k].r<l)return 0;
	if(a[k].l>=l&&a[k].r<=r)return a[k].maxn;
	return max(query(l,r,k<<1),query(l,r,k<<1|1));
}
signed main()
{
	int t,n,k,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			qz[i]=read();
		}
		while(!pq.empty())pq.pop();
		build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			if(i>1&&qz[i]==qz[i-1])
			{
				change(i,1,0);
				continue;
			}
			now[i]=min(qz[i]/qz[1],k);
			if(now[i]<=qz[i]&&(qz[i]/(qz[i]/now[i])+1)<=k)pq.push(make_pair(qz[i]/(qz[i]/(qz[i]/now[i])+1),i));
			//printf("orz%d\n",qz[i]/(qz[i]/(qz[i]/now[i])+1));
			change(i,1,qz[i]/now[i]); 
		}
		ans=1000000000;
		for(int i=qz[1];i>=1;i--)
		{
			while(!pq.empty()&&pq.top().first==i)
			{
				int x=pq.top().second;
				now[x]=((qz[x]/(qz[x]/now[x]))+1);
				//printf("%d %d %d %d\n",x,qz[x],pq.top().first,now[x]);
				pq.pop();
				change(x,1,qz[x]/now[x]);
				if(now[x]<=qz[x]&&(qz[x]/(qz[x]/now[x])+1)<=k)pq.push(make_pair(qz[x]/(qz[x]/(qz[x]/now[x])+1),x));
			}
			//for(int j=1;j<=n;j++)printf("%d ",query(j,j,1));
			//printf("\n");
			ans=min(ans,a[1].maxn-i);
			if(ans==0)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}