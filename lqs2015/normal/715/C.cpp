#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
long long n,m,x,y,z,ans,sub[111111],inv[111111],pw[111111],cnt,l[111111];
vector<pair<long long,long long> > g[111111];
bool conc[111111];
vector<long long> v,vv;
long long find(long long p)
{
	long long ll=1,rr=cnt;
	while(ll<=rr)
	{
		long long mid=(ll+rr)/2;
		if (l[mid]==p) return vv[mid];
		else if (l[mid]>p) rr=mid-1;
		else ll=mid+1;
	}
	return -1;
}
long long calc(long long p)
{
	long long y=find(p);
	if (y==-1) return 0;
	return v[y];
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
long long inver(long long a,long long m)
{
	long long x,y;
	exgcd(a,m,x,y);
	return (m+x%m)%m;
}
void calsub(long long i,long long fa)
{
	sub[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first;
		if (conc[to] || to==fa) continue;
		calsub(to,i);
		sub[i]+=sub[to];
	}
}
pair<long long,long long> findgrav(long long i,long long fa,long long all)
{
	pair<long long,long long> res=make_pair(1e9,1e9);
	long long mx=0,sum=0;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first;
		if (conc[to] || to==fa) continue;
		res=min(res,findgrav(to,i,all));
		mx=max(mx,sub[to]);
		sum+=sub[to];
	}
	mx=max(mx,all-sum);
	res=min(res,make_pair(mx,i));
	return res;
}
void afs(long long i,long long fa,long long sum,long long len)
{
	l[++cnt]=sum;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to!=fa && !conc[to]) afs(to,i,(sum+pw[len]*val)%m,len+1);
	}
}
void bfs(long long i,long long fa,long long sum,long long f,long long len)
{
	long long y=find(sum);
	if (y!=-1) v[y]+=f;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to!=fa && !conc[to]) bfs(to,i,(sum+pw[len]*val)%m,f,len+1);
	}
}
void cfs(long long i,long long fa,long long sum,long long len)
{
	long long t=(m-sum)*inv[len]%m;
	ans+=calc(t);
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val=g[i][j].second;
		if (to!=fa && !conc[to]) cfs(to,i,(sum*10+val)%m,len+1);
	}
}
void gravity(long long i)
{
	calsub(i,0);
	long long pos=findgrav(i,0,sub[i]).second;
	conc[pos]=1;
	for (long long j=0;j<g[pos].size();j++)
	{
		long long to=g[pos][j].first;
		if (!conc[to]) gravity(to);
	}
	cnt=1;
	l[1]=0;
	for (long long j=0;j<g[pos].size();j++)
	{
		long long to=g[pos][j].first,val=g[pos][j].second;
		if (!conc[to]) afs(to,pos,val%m,1);
	}
	v.clear();vv.clear();
	sort(l+1,l+cnt+1);
	long long prev=-2333;
	vv.push_back(-1); 
	for (long long j=1;j<=cnt;j++)
	{
		if (l[j]!=prev) v.push_back(1);
		else v[v.size()-1]++;
		vv.push_back(v.size()-1); 
		prev=l[j]; 
	}
	ans+=calc(0);
	ans--;
	for (long long j=0;j<g[pos].size();j++)
	{
		long long to=g[pos][j].first,val=g[pos][j].second;
		if (!conc[to])
		{
			bfs(to,pos,val%m,-1,1);
			cfs(to,pos,val%m,1);
			bfs(to,pos,val%m,1,1);
		}
	}
	conc[pos]=0;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	long long aa=1;
	for (long long i=1;i<=n;i++)
	{
		aa=aa*10%m;
		inv[i]=inver(aa,m);
	}
	pw[0]=1;
	for (long long i=1;i<=n;i++) pw[i]=pw[i-1]*10%m;
	ans=0;
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		x++;y++;
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	gravity(1);
	printf("%I64d\n",ans);
	return 0;
}