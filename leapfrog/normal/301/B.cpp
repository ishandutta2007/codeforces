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
int n,d,a[105],X[105],Y[105];ll ds[105][105];
inline int A(int x) {return x<0?-x:x;}
int main()
{
	read(n),read(d);for(int i=2;i<n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(X[i]),read(Y[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i^j)
		ds[i][j]=1ll*(A(X[i]-X[j])+A(Y[i]-Y[j]))*d-a[j];
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
	return printf("%lld\n",ds[1][n]),0;
}