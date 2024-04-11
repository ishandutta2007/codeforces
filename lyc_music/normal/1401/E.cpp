#include<bits/stdc++.h>
#define int long long 
#define N 1000005
using namespace std;
int n,m,x,y,z,l[N],r[N],u[N],d[N],cnt,ans,tree[N<<2];
struct sxy
{
	int p,v;
}h[N];
bool Cmp(sxy aa,sxy bb)
{
	return aa.v<bb.v;
}
bool Cmp1(sxy aa,sxy bb)
{
	return aa.v>bb.v;
}
    int lowbit(int k)
    {
        return k & -k;
    }
    void add(int x,int k)
    {
        while(x<=N)
        {
            tree[x]+=k;
            x+=lowbit(x);
        }
    }
    int sum(int x)
    {
        int ans=0;
        while(x!=0)
        {
            ans+=tree[x];
            x-=lowbit(x);
        }
        return ans;
    }
signed main()
{
	cin>>n>>m;
	for (int i=1;i<1000000;i++)
	{
		l[i]=d[i]=0;
		r[i]=u[i]=1000000;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		if (z==1000000) r[x]=min(r[x],y);
		if (y==0) l[x]=max(l[x],z);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (z==1000000) u[x]=min(u[x],y);
		if (y==0) d[x]=max(d[x],z);
	}
	for(int i=1;i<1000000;++i)
    {
        if(l[i]>=r[i])
        {
            l[i]=1000000;
            r[i]=1000000;
            ++ans;
        }
        if(d[i]>=u[i])
        {
            d[i]=1000000;
            u[i]=1000000;
            ++ans;
        }
    }
	for (int i=1;i<1000000;i++)
	{
		h[i].p=i;
		h[i].v=l[i];
		add(i,1);
    }
	sort(h+1,h+1000000,Cmp);
	cnt=0;
	for (int i=1;i<1000000;i++)
	{
		while (++cnt<1000000&h[cnt].v<i)
		{
			add(h[cnt].p,-1);
		}
		cnt--;
		ans+=sum(d[i])+sum(1000000)-sum(u[i]-1);
	}memset(tree,0,sizeof(tree));
	for (int i=1;i<1000000;i++)
	{
		h[i].p=i;
		h[i].v=r[i];
		add(i,1);
	}
	sort(h+1,h+1000000,Cmp1);
    cnt=0;
    for(int i=999999;i;--i)
    {
        while(++cnt<1000000&&h[cnt].v>i)
        {
            add(h[cnt].p,-1);
        }
        --cnt;
        ans+=sum(d[i]);
        ans+=sum(1000000)-sum(u[i]-1);
    }
    cout<<ans+1<<endl;
}