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
int n,s1,s2,a[100005];
inline char chk(int k)
{
	int l=-1e9,r=1e9;for(int i=n;i;i--)
		if(l<=a[i]&&a[i]<=r) l=a[i]-k,r=a[i]+k;
		else l=max(l,a[i]-k),r=min(r,a[i]+k);
	return (l<=s1&&s1<=r)||(l<=s2&&s2<=r);
}
int main()
{
	read(n),read(s1),read(s2);for(int i=1;i<=n;i++) read(a[i]);
	int l=abs(s2-s1),r=1e9,rs=1e9;while(l<=r)
		{int md=(l+r)>>1;if(chk(md)) r=md-1,rs=md;else l=md+1;}
	return printf("%d\n",rs),0;
}