//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[3005];
int main()
{
	read(n);int tot=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i]>a[j]) tot++;
	return printf("%d\n",(tot<<1)-(tot&1)),0;
}