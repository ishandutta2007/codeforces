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
int n,c1,c2;
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),c1+=x==1,c2+=x==2;
	int rs=min(c2,c1);c1-=rs,c2-=rs,rs+=c1/3,printf("%d\n",rs);
}