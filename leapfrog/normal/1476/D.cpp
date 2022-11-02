//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,l[300005][2],r[300005][2];char c[300005];
inline void solve()
{
	read(n),scanf("%s",c+1);for(int i=0;i<=n;i++) l[i][0]=l[i][1]=r[i][0]=r[i][1]=i;
	for(int i=1;i<=n;i++) c[i]=c[i]=='L';
	for(int i=1;i<=n;i++) l[i][c[i]]=l[i-1][!c[i]];
	for(int i=n;i>=1;i--) r[i-1][c[i]]=r[i][!c[i]];
	for(int i=0;i<=n;i++)
	{
		int le=i,ri=i;
		if(i&&c[i]) le=l[i][c[i]];
		if(i^n&&!c[i+1]) ri=r[i][c[i+1]];
		printf("%d ",ri-le+1);
	}
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}