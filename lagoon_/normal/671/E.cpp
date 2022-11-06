#include<bits/stdc++.h>
#define re register
int n,k,ans=1;
int w[100100],g[100100];
long long w1[100100],w2[100100];
int ii;
struct seg
{
	long long mx,lr,vmi;
}f[801000];
long long tg[800100];
int ll[800100],rr[800100];
inline void adv(re int i,re long long v)
{
	f[i].mx+=v;f[i].lr+=v;tg[i]+=v;
}
inline void pd(re int i)
{
	if(tg[i])
	{
		adv(i*2,tg[i]);
		adv(i*2+1,tg[i]);
		tg[i]=0;
	}
}
long long ct(re int i,re long long v)
{
	if(ll[i]==rr[i])return f[i].vmi+std::max(v,f[i].mx);
	pd(i);
	return f[i*2].mx>=v?std::min(f[i].lr,ct(i*2,v)):std::min(v+f[i*2].vmi,ct(i*2+1,v));
}
void pu(re int i)
{
	f[i].mx=std::max(f[i*2].mx,f[i*2+1].mx);
	f[i].vmi=std::min(f[i*2].vmi,f[i*2+1].vmi);
	f[i].lr=ct(i*2+1,f[i*2].mx);
}
std::vector<int>to[200100];
int q[200100],ta,l1,nw;
long long v1,v2;
void add(re int i,re int l,re int r)
{
	if(l>=l1){adv(i,v1);return;}
	re int mid=(l+r)/2;
	pd(i);
	if(l1<=mid)add(i*2,l,mid);
	add(i*2+1,mid+1,r);
	pu(i);
	//printf("***%d %d %d mx:%lld vmi:%lld lr:%lld\n",i,l,r,f[i].mx,f[i].vmi,f[i].lr);
}
void build(re int i,re int l,re int r)
{
	ll[i]=l;rr[i]=r;
	if(l==r){f[i].mx=w2[l/2+1];f[i].vmi=-w2[l/2+1];return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	pu(i);
	//printf("***%d %d %d mx:%lld vmi:%lld lr:%lld\n",i,l,r,f[i].mx,f[i].vmi,f[i].lr);
}
void qry(re int i,re int l,re int r)
{
	if(l>=l1){if(ct(i,v1)<=k)nw=i,v2=v1;v1=std::max(v1,f[i].mx);return;}
	pd(i);
	re int mid=(l+r)/2;
	if(l1<=mid)qry(i*2,l,mid);
	qry(i*2+1,mid+1,r);
}
void qry1(re int i,re int l,re int r)
{
	if(l==r){ans=std::max(ans,l/2-l1/2+1);return;}
	pd(i);
	re int mid=(l+r)/2;
	if(ct(i*2+1,std::max(f[i*2].mx,v1))<=k)v1=std::max(v1,f[i*2].mx),qry1(i*2+1,mid+1,r);
	else qry1(i*2,l,mid);
}
void dfs(re int a)
{
	for(re int j=0;j<to[a].size();j++)
	{
		re int x=to[a][j];//printf("******%d %d\n",a,x);
		l1=2*a-3;v1=w1[x]-w1[a];//printf("****l1:%d v1:%lld\n",l1,v1);
		add(1,0,2*n-1);
		dfs(x);
		l1=2*a-3;v1=w1[a]-w1[x];
		add(1,0,2*n-1);
	}
	l1=2*a-2;v1=-1ll<<60;v2=-1ll<<60;nw=0;
	qry(1,0,2*n-1);
	v1=v2;
	//printf("*****%d %d %d %d\n",a,nw,ll[nw],rr[nw]);
	if(nw)qry1(nw,ll[nw],rr[nw]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(re int i=1;i<n;i++)scanf("%d",&w[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&g[i]);
	for(re int i=1;i<n;i++)w1[i+1]=g[i]-w[i]+w1[i];
	for(re int i=1;i<n;i++)w2[i+1]=g[i+1]-w[i]+w2[i];
	build(1,0,2*n-1);
	for(re int i=1;i<=n;i++)
	{
		while(ta&&w1[q[ta]]>w1[i])to[i].push_back(q[ta--]);
		q[++ta]=i;
	}
	for(re int i=1;i<=ta;i++)dfs(q[i]);
	printf("%d\n",ans);
}