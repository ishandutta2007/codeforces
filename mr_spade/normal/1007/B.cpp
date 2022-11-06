#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#include<cstdio>
inline int read()
{
	int res=0;
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		res=res*10+x-'0';
	return res;
}
inline void write(int x)
{
	if(x>=10)
		write(x/10);
	putchar(x%10+'0');
	return;
}
const int N=1e5+5;
int a[3];
int s[N],cnt[8];
inline void add(int x,int i)
{
	cnt[s[x]]--;
	cnt[s[x]|=1<<i]++;
	return;
}
inline void f(int x)
{
	register int i;
	for(i=1;i*i<=a[x];i++)
		if(a[x]%i==0)
		{
			if(i*i==a[x])
				add(i,x);
			else
				add(i,x),add(a[x]/i,x);
		}
	return;
}
inline void sub(int x,int i)
{
	cnt[s[x]]--;
	cnt[s[x]^=1<<i]++;
	return;
}
inline void fi(int x)
{
	register int i;
	for(i=1;i*i<=a[x];i++)
		if(a[x]%i==0)
		{
			if(i*i==a[x])
				sub(i,x);
			else
				sub(i,x),sub(a[x]/i,x);
		}
	return;
}
inline void solve()
{
	int ans=0;
	register int i;
	a[0]=read();a[1]=read();a[2]=read();
	for(i=0;i<3;i++)
		f(i);
	ans+=cnt[7]*(cnt[7]-1)*(cnt[7]-2)/6;
	ans+=cnt[7]*(cnt[7]-1);
	ans+=cnt[7];
	ans+=cnt[7]*(cnt[7]-1)/2*(cnt[1]+cnt[3]+cnt[5])+cnt[7]*(cnt[1]+cnt[3]+cnt[5]);
	ans+=cnt[7]*(cnt[7]-1)/2*(cnt[2]+cnt[6])+cnt[7]*(cnt[2]+cnt[6]);
	ans+=cnt[7]*(cnt[7]-1)/2*(cnt[4])+cnt[7]*(cnt[4]);
	ans+=cnt[7]*cnt[3]*(cnt[3]-1)/2+cnt[7]*cnt[3];
	ans+=cnt[7]*cnt[5]*(cnt[5]-1)/2+cnt[7]*cnt[5];
	ans+=cnt[7]*cnt[6]*(cnt[6]-1)/2+cnt[7]*cnt[6];
	ans+=cnt[7]*cnt[3]*cnt[1]+cnt[7]*cnt[3]*cnt[2]+cnt[7]*cnt[3]*cnt[4];
	ans+=cnt[7]*cnt[5]*cnt[1]+cnt[7]*cnt[5]*cnt[4]+cnt[7]*cnt[5]*cnt[2];
	ans+=cnt[7]*cnt[6]*cnt[2]+cnt[7]*cnt[6]*cnt[4]+cnt[7]*cnt[6]*cnt[1];
	ans+=cnt[7]*cnt[1]*cnt[2]+cnt[7]*cnt[1]*cnt[4]+cnt[7]*cnt[2]*cnt[4];
	ans+=cnt[7]*cnt[3]*cnt[5]+cnt[7]*cnt[3]*cnt[6]+cnt[7]*cnt[5]*cnt[6];
	ans+=cnt[3]*(cnt[3]-1)/2*(cnt[4]+cnt[5]+cnt[6])+cnt[3]*(cnt[4]+cnt[5]+cnt[6]);
	ans+=cnt[5]*(cnt[5]-1)/2*(cnt[2]+cnt[3]+cnt[6])+cnt[5]*(cnt[2]+cnt[3]+cnt[6]);
	ans+=cnt[6]*(cnt[6]-1)/2*(cnt[1]+cnt[3]+cnt[5])+cnt[6]*(cnt[1]+cnt[3]+cnt[5]);
	ans+=cnt[3]*cnt[1]*(cnt[4]+cnt[5]+cnt[6])+cnt[3]*cnt[2]*(cnt[4]+cnt[5]+cnt[6]);
	ans+=cnt[5]*cnt[1]*(cnt[2]+cnt[6])+cnt[5]*cnt[4]*(cnt[2]+cnt[3]+cnt[6]);
	ans+=cnt[6]*cnt[2]*(cnt[1]+cnt[5])+cnt[6]*cnt[4]*(cnt[1]+cnt[3]);
	ans+=cnt[3]*cnt[5]*cnt[6];
	ans+=cnt[1]*cnt[2]*cnt[4];
	write(ans);putchar('\n');
	for(i=0;i<3;i++)
		fi(i);
	return;
}
signed main()
{
	int T;
	T=read();
	while(T--)
		solve();
	return 0;
}