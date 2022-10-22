#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,B=4e2+5;
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
}e[2*N];
int n,m,q,lim,b[N],id[N],big,hd[N],cnt,is/*intersection size*/[B][N];
long long a[N],ba[B],tag[B];bool in[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n);read(m);read(q);
	while(lim*lim<n)++lim;
	F(i,0,n)read(a[i]);
	F(i,0,m)
	{
		int k;read(k);
		hd[i]=-1;
		if(k>lim)id[b[i]=big++]=i;else b[i]=-1;
		while(k--)
		{
			int x;read(x);
			adline(i,--x);
		}
		if(~b[i])for(int j=hd[i];~j;j=e[j].next)ba[b[i]]+=a[e[j].to];
	}
	F(i,0,big)
	{
		F(j,0,n)in[j]=false;
		for(int j=hd[id[i]];~j;j=e[j].next)in[e[j].to]=true;
		F(k,0,m)for(int j=hd[k];~j;j=e[j].next)if(in[e[j].to])++is[i][k];
	}
	while(q--)
	{
		char op[2];scanf("%s",op);
		if(op[0]=='?')
		{
			int u;long long ans=0;
			read(u);--u;
			if(~b[u])ans=ba[b[u]];
			else for(int i=hd[u];~i;i=e[i].next)ans+=a[e[i].to];
			F(i,0,big)ans+=tag[i]*is[i][u];
			printf("%lld\n",ans);
		}
		else
		{
			int u;long long w;read(u);read(w);--u;
			if(~b[u])tag[b[u]]+=w;
			else
			{
				for(int i=hd[u];~i;i=e[i].next)a[e[i].to]+=w;
				F(i,0,big)ba[i]+=is[i][u]*w;
			}
		}
	}
	return 0;
}