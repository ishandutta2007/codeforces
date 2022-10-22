#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
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
	int next,to,dis;
}e[2*N];
int n,m,hd[N],cnt,len[N],val[N],pre[N],last[N],q[4*N],qf=2*N,qr=2*N,id[N],fsb[N],sta[N],top,fffsssbbb[N];
void adline(int u,int v,int w){e[cnt].to=v;e[cnt].dis=w;e[cnt].next=hd[u];hd[u]=cnt++;}
bool cmp(int u,int v){return len[u]<len[v];}
int main()
{
	bool started=false;
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(u=n-1-u,v=n-1-v,w);adline(v,u,w);
	}
	q[qr++]=0;
	F(i,1,n)len[i]=fffsssbbb[i]=INF;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to,w=!!(e[i].dis||len[u]);
			if(len[v]>len[u]+w)len[v]=len[pre[v]=u]+w,q[(w?qr++:--qf)]=v;
		}
	}
	qf=qr=2*N;
	q[qr++]=0;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)if(!e[i].dis)
		{
			int v=e[i].to;
			if(fffsssbbb[v]>fffsssbbb[u]+1)fffsssbbb[v]=fffsssbbb[pre[v]=u]+1,q[qr++]=v;
		}
	}
	F(i,0,n)id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n)val[i]=INF;
	for(int l=0,r=0;l<n;l=r)
	{
		while(r<n&&len[id[l]]==len[id[r]])++r;
		F(i,l,r)fsb[i-l]=val[id[i]];
		sort(fsb,fsb+r-l);
		F(i,l,r)val[id[i]]=lower_bound(fsb,fsb+r-l,val[id[i]])-fsb;
		F(sb,l,r)
		{
			int u=id[sb];
			for(int i=hd[u];~i;i=e[i].next)
			{
				int v=e[i].to;if(len[v]!=len[u]+1)continue;
if(val[u]*10+e[i].dis<val[v]||(val[u]*10+e[i].dis==val[v]&&fffsssbbb[u]<fffsssbbb[v]))
val[v]=val[pre[v]=u]*10+(last[v]=e[i].dis),fffsssbbb[v]=fffsssbbb[u];
			}
		}
	}
	for(int i=n-1;i;i=pre[i])sta[top++]=i;
	sta[top++]=0;
	for(int i=top-2;~i;--i)if((started=started||last[sta[i]]))printf("%d",last[sta[i]]);
	if(!started)printf("0");
	printf("\n%d\n",top);
	F(i,0,top)printf("%d ",n-1-sta[i]);
	puts("");
	return 0;
}