#include<bits/stdc++.h>
#define re register
struct eg{int to,c,nx;}e[20010];
int la[10010],cur[10010],qq[10100],d[10100],ta,cnt=1;
int S,T,N;
inline void addE(re int a,re int b,re int c)
{
	e[++cnt]=(eg){b,c,la[a]};la[a]=cnt;
	e[++cnt]=(eg){a,0,la[b]};la[b]=cnt;
}
bool bfs()
{
	memset(d,0,sizeof(d));
	memcpy(cur,la,sizeof(la));
	qq[ta=1]=T;d[T]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=qq[i];
		for(re int j=la[x];j;j=e[j].nx)if(e[j^1].c&&!d[e[j].to])
		{
			d[e[j].to]=d[x]+1;
			if(e[j].to==S)return 1;
			qq[++ta]=e[j].to;
		}
	}
	return 0;
}
int dfs(re int x,re int fl)
{
	if(x==T)return fl;
	re int ff=fl;
	for(re int&j=cur[x];j;j=e[j].nx)if(e[j].c&&d[e[j].to]==d[x]-1)
	{
		re int c=dfs(e[j].to,std::min(e[j].c,ff));
		if(c)
		{
			ff-=c;e[j].c-=c;e[j^1].c+=c;
			if(!ff)return fl;
		}else d[e[j].to]=0;
	}
	return fl-ff;
}
int nans;
int dinic()
{
	re int ans=0;
	for(;bfs();ans+=dfs(S,1<<30));
	return ans;
}
int n,m,k,q,nc[20][20010],f[2011],S1,ww[20],ws[2011],lg[2011];
void dfs(re int nn)
{
	if(nn>=k){f[S1]=nans;return;}
	dfs(nn+1);
	S1+=(1<<nn);
	for(re int i=2;i<=cnt;i++)nc[nn][i]=e[i].c;
	e[nn*2+2].c=25;
	re int nw=nans;
	nans+=dinic();
	dfs(nn+1);
	for(re int i=2;i<=cnt;i++)e[i].c=nc[nn][i];
	e[nn*2+2].c=0;
	nans=nw;
	S1-=(1<<nn);
}

namespace io
{
	char B[1<<15]={0},*S=B,*T=B;
	#define gc (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
	int F()
	{
		re char c=0;
		int f=0,a=0;
		for(;!isdigit(c=gc)&&c!='-';);
		for(c=='-'?f=1:a=c-48;isdigit(c=gc);)a=(a<<1)+(a<<3)+c-48;
		return f?-a:a;
	}
}
#define F() io::F()
int main()
{
	re int x,y,w;
	n=F();m=F();k=F();q=F();
	S=1;T=n;N=n;
	for(re int i=1;i<=m;i++)
	{
		x=F();y=F();w=F();
		addE(x,y,w);
	}
	nans=dinic();
	dfs(0);
	for(re int i=1;i<=k;i++)lg[1<<(i-1)]=i;
	re int ks=(1<<k)-1;
	for(;q--;)
	{
		for(re int i=1;i<=k;i++)ww[i]=F();
		for(re int i=1;i<(1<<k);i++)ws[i]=ws[i-(i&-i)]+ww[lg[i&-i]];
		re int ans=1<<30;
		for(re int i=0;i<(1<<k);i++)ans=std::min(ans,f[i]+ws[ks-i]);
		printf("%d\n",ans);
	}
}