#line 1 "a.cpp"
using namespace std;
#line 1 "/home/kotatsugame/library/tool/FastIO.cpp"
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
#line 3 "a.cpp"
const int LIM=3e6;
int N,C[LIM+1];
long long cnt[LIM+1];
main()
{
	N=rd_uint();
	for(int i=0;i<N;i++)C[rd_uint()]++;
	for(int i=1;i<=LIM;i++)
	{
		if((long long)i*i<=LIM)cnt[i*i]+=(long long)C[i]*(C[i]-1);
		else cnt[LIM]+=(long long)C[i]*(C[i]-1);
		int rest=N-C[i];
		for(int j=1;(long long)i*j<=LIM;j++)
		{
			if(i!=j)cnt[i*j]+=(long long)C[i]*C[j],rest-=C[j];
		}
		cnt[LIM]+=(long long)C[i]*rest;
	}
	for(int i=LIM;i>=1;i--)cnt[i-1]+=cnt[i];
	int M=rd_uint();
	for(;M--;)
	{
		int p=rd_uint();
		wt(cnt[p]);
		wt('\n');
	}
}