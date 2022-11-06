#include<cstdio>
#include<bitset>
using std::bitset;
int n,m;
bitset<10>a,b;
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
	if(x>=10)
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
inline int solve()
{
	int i,ans(0);
	for(i=0;i<=9;i++)
		if(a[i]&&b[i])
			return i;
	for(i=1;i<=9;i++)
		if(a[i])
			break;
	ans=(i<<3)+(i<<1);
	for(i=0;i<=9;i++)
		if(b[i])
		{
			ans+=i;
			break;
		}
	if(ans%10*10+ans/10<ans)
		ans=ans%10*10+ans/10;
	return ans;
}
signed main()
{
	int i;
	n=read();m=read();
	for(i=1;i<=n;i++)
		a[read()]=1;
	for(i=1;i<=m;i++)
		b[read()]=1;
	writeln(solve());
	return 0;
}