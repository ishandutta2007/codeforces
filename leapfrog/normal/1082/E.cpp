//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,k,a[500005],b[500005];
int main()
{
	read(n),read(k);int mx=0,tot=0;
	for(int i=1,x;i<=n;i++)
	{
		read(x);if(x==k) {++tot;continue;}
		else if(a[x]&&a[x]+b[x]>=tot) a[x]+=b[x]-tot;else a[x]=0;
		b[x]=tot,++a[x],mx=max(mx,a[x]);
	}
	return printf("%d\n",mx+tot),0;
}