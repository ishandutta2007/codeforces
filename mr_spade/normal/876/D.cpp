#include<cstdio>
const int N(3e5+5);
int n,head;
bool a[N];
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
signed main()
{
	int i,j;
	n=read();head=n+1;
	write(1);putchar(' ');
	for(i=1;i<=n;i++)
	{
		a[read()]=true;
		while(a[head-1])
			head--;
		write(i-(n-head+1)+1);putchar(' ');
	}
	return putchar('\n'),0;
}