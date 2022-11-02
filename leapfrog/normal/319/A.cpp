//
#include<bits/stdc++.h>
using namespace std;const int P=1000000007;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,r;char c[105];
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	scanf("%s",c+1),n=strlen(c+1),r=0;
	for(int i=1;i<=n;i++) if(c[i]&1) r=(r+1ll*ksm(2,n+n-i-1))%P;
	return printf("%d\n",r),0;
}