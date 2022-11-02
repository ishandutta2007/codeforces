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
char c[105];int T,n,Q,l,r,le[2],ri[2];
inline void solve(int l,int r) {if(le[c[l]&1]==l&&ri[c[r]&1]==r) puts("NO");else puts("YES");}
int main()
{
	for(read(T);T--;)
	{
		read(n),read(Q),memset(ri,0,sizeof(ri));
		scanf("%s",c+1),memset(le,0,sizeof(le));
		for(int i=1;i<=n;i++) {ri[c[i]&1]=i;if(!le[c[i]&1]) le[c[i]&1]=i;}
		while(Q--) read(l),read(r),solve(l,r);
	}
}