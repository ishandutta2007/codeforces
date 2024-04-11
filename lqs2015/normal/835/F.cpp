#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long head[222222],nxt[444444],to[444444],val[444444],n,cnt,x,y,z,pa[222222],pav[222222],cur,w[222222],d[222222],len;
long long pre[222222],suf[222222],ans,premx[222222],sufmx[222222],mx,mx1[222222],mx2[222222],mxw[222222];
bool used[222222],incycle[222222],f;
vector<pair<long long,long long> > cycle;
void addedge(long long x,long long y,long long vl)
{
	cnt++;
	to[cnt]=y;val[cnt]=vl;
	nxt[cnt]=head[x];head[x]=cnt;
}
void dfs(long long i,long long fa)
{
	used[i]=1;
	for (long long j=head[i];j;j=nxt[j])
	{
		if (to[j]==fa) continue;
		if (used[to[j]])
		{
			if (f) return;
			cur=i;
			while(cur!=to[j])
			{
				cycle.push_back(make_pair(cur,pav[cur]));
				incycle[cur]=1;
				cur=pa[cur]; 
			}
			incycle[to[j]]=1;
			cycle.push_back(make_pair(to[j],val[j]));
			f=1;
			return; 
		}
		else 
		{
			pa[to[j]]=i;pav[to[j]]=val[j];
			dfs(to[j],i);
		}
	}
}
void dft(long long id,long long i,long long fa,long long dep)
{
	mx=max(mx,dep);
	for (long long j=head[i];j;j=nxt[j])
	{
		if (incycle[to[j]] || to[j]==fa) continue;
		dft(id,to[j],i,dep+val[j]);
		if (mx1[to[j]]+val[j]>mx1[i])
		{
			mx2[i]=mx1[i];
			mx1[i]=mx1[to[j]]+val[j];
		}
		else if (mx1[to[j]]+val[j]>mx2[i]) mx2[i]=mx1[to[j]]+val[j];
	}
	mxw[id]=max(mxw[id],mx1[i]+mx2[i]);
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	dfs(1,0);
	for (long long i=0;i<cycle.size();i++)
	{
		mx=0;
		dft(i,cycle[i].first,0,0);
		w[i]=mx;
	}
	d[0]=0;
	for (long long i=1;i<cycle.size();i++)
	{
		d[i]=d[i-1]+cycle[i-1].second;
	}
	len=d[(long long)cycle.size()-1]+cycle[(long long)cycle.size()-1].second;
	pre[0]=d[0]+w[0];mx=w[0];
	for (long long i=1;i<cycle.size();i++)
	{
		pre[i]=max(pre[i-1],d[i]+w[i]);
		premx[i]=max(premx[i-1],d[i]+w[i]+mx);
		mx=max(mx,w[i]-d[i]);
	}
	mx=-1e16;sufmx[(long long)cycle.size()]=-1e16;
	for (long long i=(long long)cycle.size()-1;i>=0;i--)
	{
		suf[i]=max(suf[i+1],len-d[i]+w[i]);
		sufmx[i]=max(sufmx[i+1],w[i]-d[i]+mx);
		mx=max(mx,w[i]+d[i]);
	}
	ans=1e18;
	for (long long i=0;i<cycle.size();i++)
	{
		ans=min(ans,max(pre[i]+suf[i+1],max(premx[i],sufmx[i+1])));
	}
	for (int i=0;i<cycle.size();i++)
	{
		ans=max(ans,mxw[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}