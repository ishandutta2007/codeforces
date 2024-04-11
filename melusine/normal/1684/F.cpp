#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<unordered_map>
#define int long long
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
vector<int>v[200005];
int minl[200005],bt[200005];
int las[200005];
unordered_map<int,int>ma,tid;
int cnt;
int a[200005];
signed main()
{
	int t,n,m,x,y,r,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		tid.clear();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(tid[a[i]]==0)tid[a[i]]=++cnt;
			v[tid[a[i]]].push_back(i);
			minl[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			minl[y]=min(minl[y],x);
		}
		for(int i=n-1;i>=1;i--)minl[i]=min(minl[i+1],minl[i]);
		ma.clear();
		int l=1,r;
		for(int i=1;i<=n;i++)
		{
			ma[a[i]]++;
			while(ma[a[i]]>1)
			{
				ma[a[l]]--; 
				l++;
			}
			bt[i]=l;
		}
		l=1;
		r=0;
		for(int i=1;i<=n;i++)
		{
			if(bt[i]>minl[i])r=max(r,bt[i]-1);
		}
		ans=r-l+1;
		for(l=2;l<=n;l++)
		{
			int sth=tid[a[l-1]];
			int tl=0,tr=v[sth].size()-1,mid;
			while(tl<=tr)
			{
				mid=(tl+tr)>>1;
				if(v[sth][mid]>=l-1)tr=mid-1;
				else tl=mid+1;
			}
			if(tr>=0)
			{
				//printf("%lld %lld\n",v[sth][tr],minl[l-1]);
				if(v[sth][tr]>=minl[l-1])break;
			}
			tl=0;
			tr=v[sth].size()-1;
			while(tl<=tr)
			{
				mid=(tl+tr)>>1;
				if(v[sth][mid]>r)tr=mid-1;
				else tl=mid+1;
			}
			//if(tl>=v[sth].size())continue;
			while(tl<v[sth].size()&&minl[v[sth][tl]]<=l-1)r=v[sth][tl],tl++;
			//printf("%lld %lld\n",l,r);
			ans=min(ans,r-l+1);
			if(r<l)
			{
				ans=0;
				break;
			}
		}
		for(int i=1;i<=cnt;i++)v[i].clear();
		printf("%lld\n",ans);
	}
}