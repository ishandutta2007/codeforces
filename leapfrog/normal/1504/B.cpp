//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,m,a[300005],b[300005];
inline void solve()
{
	read(n),a[n+1]=b[n+1]=0;
	for(int i=1;i<=n;i++) scanf("%1d",a+i);
	for(int i=1;i<=n;i++) scanf("%1d",b+i);
	for(int i=1;i<=n;i++) a[i]=a[i-1]+(a[i]?1:-1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+(b[i]?1:-1);
	for(int i=1;i<=n;i++) if(abs(a[i])!=abs(b[i])) return puts("NO"),void();
	for(int i=1;i<=n;i++)
	{
		int r=i;while(r<=n&&a[r+1]) r++;
		//printf("%d , %d\n",i,r);
		for(int j=i+1;j<=r;j++) if(a[i]/b[i]!=a[j]/b[j]) return puts("NO"),void();
		i=r+1;
	}
	int ed=n;while(ed>=1&&a[ed]) ed--;
	for(int i=ed+1;i<=n;i++) if(a[i]!=b[i]) return puts("NO"),void();
	puts("YES");
}
int main() {for(read(T);T--;) solve();return 0;}