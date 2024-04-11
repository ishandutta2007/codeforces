#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,K,a[2005],qw[20005],F[2005][2005];
inline void solve()
{
	read(n),read(K);int rs=1e9;
	for(int i=1;i<=n;i++) read(a[i]),qw[i]=i-a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++) F[i][j]=F[i-1][j];
		if(i<a[i]) continue;
		for(int j=0;j<=qw[i];j++) F[i][qw[i]]=max(F[i][qw[i]],F[a[i]-1][j]+1);
		for(int j=i-1;~j;j--)
		{
			int lim=qw[i],tp=j-a[i]+1;if(tp<=0) break;
			if(qw[j]>=tp&&qw[j]<=lim) F[i][lim]=max(F[i][lim],F[j][qw[j]]+1);
		}
		if(F[i][qw[i]]>=K) rs=min(rs,qw[i]);
	}
	printf("%d\n",rs==1e9?-1:rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}