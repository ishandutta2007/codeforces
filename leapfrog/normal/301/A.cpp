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
int n,a[100005];
int main()
{
	read(n);for(int i=1;i<=n+n-1;i++) read(a[i]);
	sort(a+1,a+n+n,[](int x,int y){return abs(x)<abs(y);});
	int sm=0,cnt=0;for(int i=1;i<=n+n-1;i++) cnt+=a[i]<0,sm+=abs(a[i]);
	if(!(n&1)&&cnt&1) sm-=abs(a[1])*2;
	return printf("%d\n",sm),0;
}