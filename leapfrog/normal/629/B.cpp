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
int n,rs,a[405],b[405];char fg;
int main()
{
	read(n);for(int i=1,x,y;i<=n;i++)
	{
		scanf("%s",&fg),read(x),read(y);
		for(int i=x;i<=y;i++) if(fg=='M') a[i]++;else b[i]++;
	}
	for(int i=1;i<=366;i++) rs=max(rs,min(a[i],b[i])*2);
	return printf("%d\n",rs),0;
}