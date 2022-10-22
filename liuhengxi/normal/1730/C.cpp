#include<cstdio>
#include<algorithm>
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
constexpr int N=2e5+5;
int tt;
void solve(char *s,int n)
{
	static char p[N];
	int mn=255;
	if(!n)return;
	F(i,0,n)mn=min(mn,s[i]-'0');
	bool neq=false;
	F(i,0,n)neq=neq||s[i]-'0'!=mn;
	if(!neq)return;
	int r=0,cnt=0,pp=0;
	F(i,0,n)if(s[i]-'0'==mn)r=i,++cnt;
	++r;
	F(i,0,r)if(s[i]-'0'!=mn)p[pp++]=(char)min(s[i]+1,(int)'9');
	F(i,0,cnt)s[i]=(char)(mn+'0');
	F(i,0,pp)s[i+cnt]=p[i];
	solve(s+r,n-r);
}
char s[N];
int main()
{
	read(tt);
	while(tt--)
	{
		scanf("%s",s);
		int n=0;
		while(s[n])++n;
		solve(s,n);
		sort(s,s+n);
		puts(s);
	}
	return 0;
}