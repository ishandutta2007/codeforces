//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T;char c[100005];
int main()
{
	for(read(T);T--;)
	{
		int n;read(n),scanf("%s",c+1);
		int mx=0;for(int i=n;i;i--) if(c[i]!=')') {mx=i;break;}
		int l=n-mx;if(l>n-l) puts("Yes");else puts("No");
	}
	return 0;
}