//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[205];
int main()
{
	read(n),n<<=1;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);if(a[n>>1]^a[(n>>1)+1]) puts("YES");else puts("NO");
	return 0;
}