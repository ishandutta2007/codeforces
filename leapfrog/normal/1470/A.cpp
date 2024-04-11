//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,k[500005],c[500005];
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m);ll res=0;
		for(int i=1;i<=n;i++) read(k[i]);
		for(int i=1;i<=m;i++) read(c[i]);
		sort(k+1,k+n+1);int sum=0;
		for(int i=n;i;i--) sum++,res+=c[min(sum,k[i])];
		printf("%lld\n",res);
	}
	return 0;
}