#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=(1<<20)+5;
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
}e[N<<5];
int n,m,k,ind[M],val[128],msk[17],hd[N],cnt,q[N],qf,qr,in[N];
char s[N];
int hash(const char *s)
{
	int ans=0;
	for(;*s;++s)ans=ans<<5|val[(int)*s];
	return ans;
}
void adline(int u,int v)
{
	++in[e[cnt].to=v];
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	F(i,0,26)val['a'+i]=i+1;
	read(n);read(m);read(k);
	F(i,0,1<<(5*k))ind[i]=-1;
	F(i,0,n)
	{
		scanf("%s",s);
		ind[hash(s)]=i;
	}
	F(i,0,1<<k)msk[i]=msk[i>>1]<<5|((i&1)*31);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int v,mt;
		bool bad=true;
		scanf("%s",s);read(mt);--mt;
		v=hash(s);
		F(j,0,1<<k)if(ind[v&msk[j]]==mt)bad=false;
		if(bad)return puts("NO"),0;
		F(j,0,1<<k)if(ind[v&msk[j]]!=mt&&~ind[v&msk[j]])adline(mt,ind[v&msk[j]]);
	}
	F(i,0,n)if(!in[i])q[qr++]=i;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(!--in[v])q[qr++]=v;
		}
	}
	if(qf!=n)return puts("NO"),0;
	puts("YES");
	F(i,0,n)printf("%d ",q[i]+1);
	puts("");
	return 0;
}