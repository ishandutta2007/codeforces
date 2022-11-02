//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,lim,a[100005];
int main()
{
	read(n),read(lim);for(int i=1;i<=n;i++) read(a[i]);
	int r=1;double rs=-1;for(int l=1;l<=n;l++)
	{
		r=max(r,l);while(r<n&&a[r+1]-a[l]<=lim) r++;
		if(r-l>1) rs=max(rs,1.0*(a[r]-a[l+1])/(a[r]-a[l]));
	}
	return (rs<0?puts("-1"):printf("%.10lf\n",rs)),0;
}