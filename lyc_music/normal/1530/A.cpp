//LYC_music yyds!
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int pos=1,num=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') pos=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		num=num*10+(int)(ch-'0');
		ch=getchar();
	}
	return pos*num;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}
void writesp(int x)
{
	write(x);
	putchar(' ');
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
int T,ans,n;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		ans=0;
		while (n)
		{
			ans=max(ans,n%10);
			n/=10;
		}
		writeln(ans);
	}
}