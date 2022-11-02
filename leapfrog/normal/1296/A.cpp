#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int t,n,a[2005];
int main()
{
	for(read(t);t--;)
	{
		read(n);char fg=0,fl=0;
		for(int i=1;i<=n;i++) read(a[i]),fg|=(a[i]&1),fl|=!(a[i]&1);
		if(!fg) puts("NO");else if(!fl&&!(n&1)) puts("NO");else puts("YES");
	}
	return 0;
}