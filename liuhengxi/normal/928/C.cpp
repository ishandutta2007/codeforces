#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5,S=1e4+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[N*N];
int n,to[S][26],tval[S],scnt=1,ind,dis[N],maxver[N],rver;
int uname[N*N],uver[N*N],vname[N*N],vver[N*N],ecnt,val[N];
int qname[N],qver[N],qdis[N],qf,qr,hd[N*N],cnt,id[N],m;
bool vis[N*N];
char s[12],t[N][12]/*real string*/;
bool cmp(int u,int v)
{
	F(i,0,12)if(t[u][i]!=t[v][i])return t[u][i]<t[v][i];
	return false;
}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int add()
{
	int j=0;
	for(int i=0;s[i];++i)
	{
		int x=s[i]-'a';
		if(!to[j][x])to[j][x]=scnt++;
		j=to[j][x];
	}
	if(!tval[j])
	{
		for(int i=0;s[i];++i)t[ind][i]=s[i];
		tval[j]=++ind;
	}
	return tval[j]-1;
}
int bs(int x)
{
	int l=0,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<val[mid])r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	read(n);
	F(i,0,n)
	{
		int u,uu,m;
		scanf("%s",s);read(uu);
		u=add();
		if(i==0)rver=uu;
		read(m);
		while(m--)
		{
			int v,vv;scanf("%s",s);v=add();read(vv);
			uname[ecnt]=u;
			vname[ecnt]=v;
			uver[ecnt]=uu;
			vver[ecnt]=vv;
			++ecnt;
		}
		val[i]=uu;
	}
	sort(val,val+n);
	F(i,0,n*n)hd[i]=-1;
	F(i,0,ecnt)
	{
		uver[i]=bs(uver[i]),vver[i]=bs(vver[i]);
		adline(uname[i]*n+uver[i],vname[i]*n+vver[i]);
	}
	rver=bs(rver);
	qver[qr++]=maxver[0]=rver;
	vis[rver]=true;
	F(i,1,n)dis[i]=INF;
	while(qf<qr)
	{
		int name=qname[qf],ver=qver[qf],udis=qdis[qf++],u=name*n+ver;
		if(udis==dis[name]&&ver==maxver[name])
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to,vname=v/n,vver=v%n;
			if(vis[v])continue;
			vis[v]=true;
			qname[qr]=vname;
			qver[qr]=vver;
			qdis[qr++]=udis+1;
			if(udis+1<dis[vname])dis[vname]=udis+1,maxver[vname]=vver;
			if(udis+1==dis[vname]&&maxver[vname]<vver)maxver[vname]=vver;
		}
	}
	F(i,1,n)if(dis[i]<INF)++m;
	F(i,1,n)id[i]=i;
	sort(id+1,id+n,cmp);
	printf("%d\n",m);
	F(i,1,n)
	{
		int j=id[i];
		if(dis[j]<INF)
		{
			printf("%s %d\n",t[j],val[maxver[j]]);
		}
	}
	return 0;
}