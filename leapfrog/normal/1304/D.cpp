//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[1000005];char c[1000005];
int main()
{
	for(read(T);T--;)
	{
		read(n),scanf("%s",c+2);
		for(int i=1;i<=n;i++) a[i]=n-i+1;
		for(int i=2,j=i;i<=n;i=++j)
		{
			while(c[j]=='<') ++j;
			reverse(a+i-1,a+j);
		}
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
		for(int i=1;i<=n;i++) a[i]=i;
		for(int i=2,j=i;i<=n;i=++j)
		{
			while(c[j]=='>') ++j;
			reverse(a+i-1,a+j);
		}
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}