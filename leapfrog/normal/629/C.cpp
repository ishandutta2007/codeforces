//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,k,f[2005][2005];char c[100005];
int main()
{
	read(n),read(m),k=n-m,f[0][0]=1,scanf("%s",c+1);int lim=0,bal=0,res=0;
	for(int i=1;i<=k;i++) for(int j=0;j<=i;j++) f[i][j]=((j<i?f[i-1][j+1]:0)+(j>0?f[i-1][j-1]:0))%P;
	for(int i=1;i<=m;i++) lim+=(c[i]=='('?1:-1),bal=min(bal,lim);
	for(int i=0;i<=k;i++) for(int j=-bal;j<=i;j++) if(n-m-i>=j+lim) res=(res+1ll*f[i][j]*f[n-m-i][j+lim]%P)%P;
	return printf("%d\n",res),0;
}