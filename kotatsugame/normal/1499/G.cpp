#line 1 "a.cpp"
#include<cstdio>
#include<vector>
using namespace std;
#line 2 "/home/kotatsugame/library/tool/FastIO.cpp"
#include<cctype>
#include<string>
const int buffer_size=1<<20;
//input
int rd_char()
{
	static char buf[buffer_size];
	static int l=buffer_size,r=buffer_size;
	if(l==r&&r==buffer_size)
	{
		r=fread(buf,sizeof(char),1<<20,stdin);
		l=0;
	}
	if(l==r)return EOF;
	return buf[l++];
}
unsigned int rd_uint()
{
	int c;
	unsigned int x=0;
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return x;
}
int rd_int()
{
	bool neg=false;
	int c=rd_char();
	long long x=0;
	if(c=='-')neg=true;
	else x=c-'0';
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return neg?-x:x;
}
unsigned long long rd_ull()
{
	int c;
	unsigned long long x=0;
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return x;
}
long long rd_ll()
{
	bool neg=false;
	int c=rd_char();
	long long x=0;
	if(c=='-')neg=true;
	else x=c-'0';
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return neg?-x:x;
}
string rd_str()
{
	string ret;
	int c;
	while((c=rd_char())!='\n'&&c!=' '&&c!=EOF)ret+=c;
	return ret;
}
//output
struct writer_struct{
	char buf[buffer_size];
	int l=0;
	~writer_struct(){fwrite(buf,sizeof(char),l,stdout);}
}writer;
void flush()
{
	fwrite(writer.buf,sizeof(char),writer.l,stdout);
	writer.l=0;
}
void wt(char c)
{
	if(writer.l==buffer_size)
	{
		fwrite(writer.buf,sizeof(char),buffer_size,stdout);
		writer.l=0;
	}
	writer.buf[writer.l++]=c;
}
void wt(unsigned int x)
{
	if(x==0)wt('0');
	else
	{
		char f[10];
		int sz=0;
		while(x)
		{
			f[sz++]=x%10+'0';
			x/=10;
		}
		while(sz)wt(f[--sz]);
	}
}
void wt(int x)
{
	if(x<0)wt('-'),x=-x;
	wt((unsigned int)x);
}
void wt(unsigned long long x)
{
	if(x==0)wt('0');
	else
	{
		char f[20];
		int sz=0;
		while(x)
		{
			f[sz++]=x%10+'0';
			x/=10;
		}
		while(sz)wt(f[--sz]);
	}
}
void wt(long long x)
{
	if(x<0)wt('-'),x=-x;
	wt((unsigned long long)x);
}
void wt(const char*s){while(*s!='\0')wt(*s++);}
void wt(const string&s){for(char c:s)wt(c);}
#line 5 "a.cpp"
const long long mod=998244353;
int N1,N2,M;
int pr[4<<17],hs[4<<17],hn[4<<17],pe[4<<17],pc[4<<17];
int ai[4<<17][2];
int ans,eh=1,id;
vector<int>es;
bool usd[4<<17];
void adj(int ei,vector<int>&a,int j)
{
	int pei=-1;
	int cnt=0;
	while(ei!=-1)
	{
		usd[ei]=true;
		if(cnt==j)a.push_back(ei);
		int tei=ei;
		if(pei==ai[ei][0])ei=ai[ei][1];
		else ei=ai[ei][0];
		pei=tei;
		cnt=1-cnt;
	}
}
void add(int ei,int ni)
{
	if(ai[ei][0]==-1)ai[ei][0]=ni;
	else ai[ei][1]=ni;
}
void add_edge(int u,int v)
{
	id++;
	ai[id][0]=ai[id][1]=-1;
	v+=N1;
	eh=eh*2%mod;
	if(pr[u]!=-1)
	{
		if(pr[v]!=-1)
		{
			if(pr[v]==u&&pr[u]==v)
			{
				if(pc[u]==0)
				{
					adj(pe[u],es,0);
				}
				else
				{
					es.push_back(id);
					adj(pe[u],es,1);
					ans=(ans+eh)%mod;
				}
			}
			else
			{
				if(pc[u]!=pc[v])
				{
					int rv=pr[v];
					pc[v]=1-pc[v];
					pc[rv]=1-pc[rv];
					ans=(ans+mod-hn[v])%mod;
					hn[v]=hn[rv]=(hs[v]-hn[v]+mod)%mod;
					ans=(ans+hn[v])%mod;
				}
				int ru=pr[u],rv=pr[v];
				pr[ru]=rv;pr[rv]=ru;
				hs[ru]=hs[rv]=((hs[ru]+hs[rv])%mod+eh)%mod;
				hn[ru]=hn[rv]=(hn[ru]+hn[rv])%mod;
				if(pc[u]==1)
				{
					hn[ru]=hn[rv]=(hn[ru]+eh)%mod;
					ans=(ans+eh)%mod;
				}
				add(pe[u],id);
				add(id,pe[u]);
				add(pe[v],id);
				add(id,pe[v]);
			}
			pr[u]=pr[v]=-1;
		}
		else
		{
			int ru=pr[u];
			pr[ru]=v;
			hs[ru]=(hs[ru]+eh)%mod;
			if(pc[u]==1)
			{
				hn[ru]=(hn[ru]+eh)%mod;
				ans=(ans+eh)%mod;
			}
			pr[u]=-1;
			pr[v]=ru;
			hs[v]=hs[ru];
			hn[v]=hn[ru];
			pe[v]=id;
			pc[v]=1-pc[u];
			add(pe[u],id);
			add(id,pe[u]);
		}
	}
	else
	{
		if(pr[v]!=-1)
		{
			int rv=pr[v];
			pr[rv]=u;
			hs[rv]=(hs[rv]+eh)%mod;
			if(pc[v]==1)
			{
				hn[rv]=(hn[rv]+eh)%mod;
				ans=(ans+eh)%mod;
			}
			pr[v]=-1;
			pr[u]=rv;
			hs[u]=hs[rv];
			hn[u]=hn[rv];
			pe[u]=id;
			pc[u]=1-pc[v];
			add(pe[v],id);
			add(id,pe[v]);
		}
		else
		{
			pr[u]=v;
			pr[v]=u;
			hs[u]=hs[v]=eh;
			hn[u]=hn[v]=eh;
			pe[u]=pe[v]=id;
			pc[u]=pc[v]=0;
			ans=(ans+eh)%mod;
		}
	}
}
main()
{
	scanf("%d%d%d",&N1,&N2,&M);
	for(int i=0;i<N1+N2;i++)pr[i]=-1;
	for(int i=0;i<M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		u--,v--;
		add_edge(u,v);
	}
	int Q;
	scanf("%d",&Q);
	for(int ccc=0;ccc<Q;ccc++)
	{
		int t;scanf("%d",&t);
		if(t==1)
		{
			int u,v;scanf("%d%d",&u,&v);
			u--,v--;
			add_edge(u,v);
			wt(ans);
			wt('\n');
		}
		else
		{
			vector<int>ret=es;
			for(int i=0;i<=id;i++)usd[i]=false;
			for(int i=0;i<N1+N2;i++)if(pr[i]!=-1&&!usd[pe[i]])
			{
				adj(pe[i],ret,pc[i]);
			}
			wt((unsigned int)ret.size());
			for(int id:ret)wt(' '),wt(id);
			wt('\n');
		}
		flush();
		fflush(stdout);
	}
}