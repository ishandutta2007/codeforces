#include<vector>
using namespace std;
#include<cstdio>
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
	fflush(stdout);
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
#include<queue>
int T;
vector<int>G[4<<17];
int vis[4<<17];
main()
{
	T=rd_uint();
	for(;T--;)
	{
		int N,M;
		N=rd_uint();
		M=rd_uint();
		for(int i=0;i<2*N;i++)vis[i]=-1,G[i].clear();
		for(int i=0;i<M;i++)
		{
			int u=rd_uint()-1;
			int v=rd_uint()-1;
			bool f=rd_str()[0]=='c';
			G[u].push_back(v+!f*N);
			G[v].push_back(u+!f*N);
			G[u+N].push_back(v+f*N);
			G[v+N].push_back(u+f*N);
		}
		int ans=0;
		for(int i=0;i<N;i++)if(vis[i]==-1&&vis[i+N]==-1)
		{
			queue<int>P;
			P.push(i);
			vis[i]=i;
			bool out=false;
			int T=0,F=0;
			while(!P.empty())
			{
				int u=P.front();P.pop();
				if(vis[u<N?u+N:u-N]==i)
				{
					out=true;
					break;
				}
				if(u<N)T++;
				else F++;
				for(int v:G[u])if(vis[v]==-1)
				{
					vis[v]=i;
					P.push(v);
				}
			}
			if(out)
			{
				ans=-1;
				break;
			}
			ans+=T<F?F:T;
		}
		wt(ans);
		wt('\n');
	}
}