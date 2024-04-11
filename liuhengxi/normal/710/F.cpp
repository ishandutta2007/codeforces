#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,H=1<<30,L=H-1;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int m,tot,q[N],qf,qr,to[N<<1][26],ind,sta[N<<1],top,f[N<<1],fail[N<<1];
char t[N<<1],*s[N]={t},qy[N];
inline int newnode()
{
	int u=top?sta[--top]:++ind;
	F(i,0,26)to[u][i]=0;
	f[u]=fail[u]=0;
	return u;
}
inline void delnode(int u){sta[top++]=u;}
struct ac
{
	int id[N],cnt,rt;
	ac(){rt=newnode();}
	void dfs(int u)
	{
		F(i,0,26)if(to[u][i]&&!(to[u][i]&H))dfs(to[u][i]);
		delnode(u);
	}
	void clear(){cnt=0;dfs(rt);rt=0;}
	void insert(const char *s)
	{
		int j=rt;
		for(;*s;++s)
		{
			int x=*s-'a';
			if(!to[j][x])to[j][x]=newnode();
			j=to[j][x];
		}
		++f[j];
	}
	void buildfail()
	{
		qf=qr=0;
		fail[rt]=rt;
		F(i,0,26)if(to[rt][i])fail[q[qr++]=to[rt][i]]=rt;else to[rt][i]=rt|H;
		while(qf<qr)
		{
			int u=q[qf++];
			f[u]+=f[fail[u]];
			F(i,0,26)if(to[u][i])fail[q[qr++]=to[u][i]]=to[fail[u]][i]&L;
			else to[u][i]=to[fail[u]][i]|H;
		}
	}
	void build()
	{
		if(rt)dfs(rt),rt=0;
		rt=newnode();
		F(i,0,cnt)insert(s[id[i]]);
		buildfail();
	}
	ac& operator+=(const ac &b)
	{
		F(i,0,b.cnt)id[cnt+i]=b.id[i];
		cnt+=b.cnt;
		build();
		return *this;
	}
	long long run(const char *s)
	{
		int j=rt;
		long long ans=0;
		for(;*s;++s)
		{
			int x=*s-'a';
			ans+=f[j=to[j][x]&L];
		}
		return ans;
	}
}tmp;
ac &create(int id)
{
	tmp.id[0]=id;tmp.cnt=1;
	return tmp;
}
struct count
{
	ac a[20];
	void add(int id)
	{
		a[0]+=create(id);
		for(int i=0;a[i].cnt>(1<<i);++i)a[i+1]+=a[i],a[i].clear();
	}
	long long run(const char *s)
	{
		long long ans=0;
		F(i,0,20)if(a[i].cnt)ans+=a[i].run(s);
		return ans;
	}
}a,b;
int main()
{
	read(m);
	while(m--)
	{
		int op;
		if(read(op)!=3)
		{
			scanf("%s",s[tot]);
			s[tot+1]=s[tot]+1;
			while(s[tot+1][-1])++s[tot+1];
			(op==1?a:b).add(tot++);
		}
		else
		{
			scanf("%s",qy);
			printf("%lld\n",a.run(qy)-b.run(qy));
		}
		fflush(stdout);
	}
	return 0;
}