#include<bits/stdc++.h>
#define N 100010
#define M 
#define V 
#define INF 0x7fffffff
#define _INF 1e18
#define oo 0x3f3f3f3f
#define inf 0x7f7f7f7f
#define int LL 
#define LL long long
#define LD long double
#define LLU unsigned long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define _FOR(i,l,r,x) for(int i=(l);i<=(r);i+=x)
#define REP(i,l,r) for(int i=(l);i>=(r);--i)
#define _REP(i,l,r,x) for(int i=(l);i>=(r);i-=x)
#define LIN(p,l) for(int p=(l);p;p=nxt[p])
#define fin(x) freopen(x".in","r",stdin)
#define fout(x) freopen(x".out","w",stdout)
using namespace std;
inline int read()
{
	char ch;int f=1,x;
	while(ch=getchar(),!isdigit(ch)) if(ch=='-') f=-1;x=(ch^48);
	while(ch=getchar(),isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline void writ(int x,char p='\n')
{
	write(x);
	putchar(p);
}
int t;
signed main()
{
	t=read();
	while(t--)
	{
		string s;
		cin>>s;
		writ(s.size());
	}
	return 0;
}