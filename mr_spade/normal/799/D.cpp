#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using std::max;
using std::min;
const int N(1e5+5),inf(1e9);
int a,b,h,w,n,ans(inf);
int s[N];
inline int read()
{
	int sum(0);
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		sum=(sum<<3)+(sum<<1)+x-'0';
	return sum;
}
inline void write(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(int x)
{
	write(x);
	putchar('\n');
	return;
}
inline bool cmp(int a,int b)
{
	return a>b;
}
inline int dfs(int h,int w,int step)
{
	if(h>=a&&w>=b)
		return step;
	if(step==n)
		return -1;
	if(s[step+1]==2)
	{
		if(h<a)
			return dfs(h<<1,w,step+1);
		return dfs(h,w<<1,step+1);
	}
	else
	{
		int ah(-1),aw(-1);
		if(h<a)
			ah=dfs(h*s[step+1],w,step+1);
		if(w<b)
			aw=dfs(h,w*s[step+1],step+1);
		if(ah==-1||aw==-1)
			return max(ah,aw);
		return min(ah,aw);
	}
}
signed main()
{
	int i;
	a=read();b=read();
	h=read();w=read();
	n=read();
	for(i=1;i<=n;i++)
		s[i]=read();
	std::sort(s+1,s+n+1,cmp);
	ans=dfs(h,w,0);
	if(ans==-1)
		ans=max(ans,dfs(w,h,0));
	else
		ans=min(ans,dfs(w,h,0));
	writeln(ans);
	return 0;
}