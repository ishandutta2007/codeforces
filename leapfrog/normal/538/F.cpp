//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,a[200005],rs[200005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++)
	{
		int l,r;for(l=r=1;l<=i-2;l=r+1)
			{r=(i-2)/((i-2)/l);if(a[(i-2)/l+1]>a[i]) rs[l]++,rs[r+1]--;}
		if(a[1]>a[i]) rs[l]++;
	}
	for(int i=2;i<n;i++) rs[i]+=rs[i-1];
	for(int i=1;i<n;i++) printf("%d%c",rs[i],i==n-1?'\n':' ');
	return 0;
}