#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... Arg>inline void read(T &t,Arg &...arg) {read(t),read(arg...);}
int main()
{
	int a,b,c,d;read(a,b,c,d);int h=c-a,m=d-b,res=(60*h+m)>>1,ansm=b+res%60,ansh=a+res/60;
	if(ansm>=60) ansm-=60,ansh++;
	if(ansh/10==0) putchar('0');
	printf("%d:",ansh);if(ansm/10==0) putchar('0');
	return printf("%d\n",ansm),0;
}