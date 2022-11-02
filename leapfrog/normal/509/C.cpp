//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct dig
{
	int len,a[355];
	inline void ditui(int k)
	{
		for(int i=1;i<=len;i++) k-=a[i];
		if(k<=0)
		{
			k=-k+1;int x=0;
			int i;for(i=len;i;i--) if(a[i]==9||x<k) x+=a[i],a[i]=0;else break;
			k=x-k,a[i]++;
		}
		for(int i=len,t;i;i--) k-=(t=min(9,a[i]+k))-a[i],a[i]=t;
	}
	inline void paint(char c)
	{
		int j=0;while(!a[j]) j++;
		while(j<=len) putchar(a[j]^48),++j;
		putchar(c);
	}
}t;int n,a[305];
int main()
{
	read(n),t.len=350;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) t.ditui(a[i]),t.paint('\n');
	return 0;
}