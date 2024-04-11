//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}
template<typename T,typename...L>
inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,a[300005];priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	ll rs=0;for(int i=n;i;i--)
	{
		if(!~a[i]) break;else q.push(a[i]);
		if((i&(-i))==i) rs+=q.top(),q.pop();
	}
	return printf("%lld\n",rs),0;
}