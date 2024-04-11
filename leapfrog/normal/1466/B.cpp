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
int T,n,a[100005];
int main()
{
//	freopen("out.txt","w",stdout);
	for(read(T);T--;)
	{
		char tag=0;read(n);for(int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);int res=0;for(int i=1;i<=n;i++) res+=a[i]!=a[i-1];
		for(int i=2;i<=n;i++) if(a[i]-a[i-1]>1) tag=0;else if(a[i]==a[i-1]) res+=!tag,tag=1;
		printf("%d\n",res);
	}
	return 0;
}