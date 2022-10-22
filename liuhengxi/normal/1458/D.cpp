#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=5e5+5;
int tt;
int n,c[2*N];
char s[N],t[N];
void dfs(int x)
{
	while(c[x-1])
	{
		--c[x-1];
		dfs(x-1);
		t[--n]='0';
	}
	while(c[x])
	{
		--c[x];
		dfs(x+1);
		t[--n]='1';
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		scanf("%s",s);
		for(n=0;s[n];++n);
		int st=N,cur=N;
		F(i,0,n)
		{
			if(s[i]=='0')++c[--cur];
			else ++c[cur++];
		}
		t[n]='\0';
		dfs(st);
		puts(t);
	}
	return 0;
}