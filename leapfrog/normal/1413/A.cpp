//
//
#include<bits/stdc++.h>
using namespace std;const int X=303;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[105],b[105];
int main()
{
	for(read(T);T--;)
	{
		read(n);
		for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
		for(int i=1;i<n;++++i) swap(b[i],b[i+1]),b[i]=-b[i];
		if(n&1)
		{
			int x=a[n-2],y=a[n-1],z=a[n];
			for(int i=-100;i<=100;i++)
				for(int j=-100;j<=100;j++)
				{
					int qwq=i*x+y*j;
					if(qwq%z==0&&qwq/z>=-100&&qwq/z<=100) {b[n-2]=i,b[n-1]=j,b[n]=qwq/z;break;}
				}
		}
		for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}