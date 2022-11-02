#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int Q,n,a[500005],sm[500005];
signed main()
{
	for(read(Q);Q--;)
	{
		read(n),sm[n+1]=1e9;
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=n;i>=1;i--) sm[i]=min(sm[i+1],a[i]);
		int p=a[1],flg=1;
		for(int i=2;i<n;i++)
		{
			if(p+sm[i+1]<a[i]) {flg=0;break;}
			if(p<a[i]) p=min(min(p,a[i]),a[i+1]-a[i]+p);else p=a[i];
		}
		if(flg) puts("YES");else puts("NO");
	}
	return 0;
}