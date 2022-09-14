#line 1 "a.cpp"
#include<cstdio>
#include<queue>
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
#line 5 "a.cpp"
int N,M,W;
int A[2000][2000];
int dist[2][2000][2000];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
long long calc(int sx,int sy,int id)
{
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)dist[id][i][j]=1e9;
	dist[id][sx][sy]=0;
	long long ret=9e18;
	queue<pair<int,int> >P;
	P.push(make_pair(sx,sy));
	while(!P.empty())
	{
		int x=P.front().first,y=P.front().second;
		P.pop();
		if(A[x][y]>0)
		{
			long long tmp=(long long)dist[id][x][y]*W+A[x][y];
			if(ret>tmp)ret=tmp;
		}
		for(int r=0;r<4;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			if(tx<0||ty<0||tx>=N||ty>=M||A[tx][ty]==-1||dist[id][tx][ty]!=(int)1e9)continue;
			dist[id][tx][ty]=dist[id][x][y]+1;
			P.push(make_pair(tx,ty));
		}
	}
	return ret;
}
main()
{
	N=rd_uint();
	M=rd_uint();
	W=rd_uint();
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)A[i][j]=rd_int();
	long long X=calc(0,0,0);
	long long Y=calc(N-1,M-1,1);
	long long ans=9e18;;
	if(dist[0][N-1][M-1]!=(int)1e9)ans=(long long)dist[0][N-1][M-1]*W;
	if(X!=(long long)9e18&&Y!=(long long)9e18&&ans>X+Y)ans=X+Y;
	if(ans==(long long)9e18)ans=-1;
	wt(ans);
	wt('\n');
}