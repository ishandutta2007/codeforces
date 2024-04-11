#include<bits/stdc++.h>
using namespace std;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool check(int n)
{
	for (int i=1;i*i<=n;i++)
	if (i*i==n) return 1;
	return 0;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		if ((check(n/2)&&n%2==0)||(check(n/4)&&n%4==0)) puts("YES");
												   else puts("NO");
	}

	return 0;
}