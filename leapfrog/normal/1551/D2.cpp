#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,K;char ch[105][105];
inline int gt(int x,int y) {x=(x+1)>>1,y=(y+1)>>1;return(x&1)<<1|(y&1);}
inline void solve()
{
	read(n),read(m),read(K);
	if(n&1)
	{
		if(K<m/2) return puts("NO"),void();
		K-=m/2;if(K&1) return puts("NO"),void();
		for(int i=1;i<=m;i++) ch[1][i]=(((i+1)/2)&1)?'z':'y';
		for(int i=2;i<=n;i+=2) for(int j=1;j<=m;j+=2)
		{
			if(K)
			{
				K--,K--;
				ch[i][j]=ch[i][j+1]='a'+gt(i,j);
				ch[i+1][j]=ch[i+1][j+1]='e'+gt(i,j);
			}
			else
			{
				ch[i][j]=ch[i+1][j]='i'+gt(i,j);
				ch[i][j+1]=ch[i+1][j+1]='m'+gt(i,j);
			}
		}
		puts("YES");
		for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++) putchar(ch[i][j]);
		return;
	}
	if(m&1)
	{
		int kk=n*m/2-K;if(kk<n/2) return puts("NO"),void();
		kk-=n/2;if(kk&1) return puts("NO"),void();
		for(int i=1;i<=n;i++) ch[i][1]=(((i+1)/2)&1)?'z':'y';
		for(int i=1;i<=n;i+=2) for(int j=2;j<=m;j+=2)
		{
			if(kk)
			{
				kk--,kk--;
				ch[i][j]=ch[i+1][j]='a'+gt(i,j);
				ch[i][j+1]=ch[i+1][j+1]='e'+gt(i,j);
			}
			else
			{
				ch[i][j]=ch[i][j+1]='i'+gt(i,j);
				ch[i+1][j]=ch[i+1][j+1]='m'+gt(i,j);
			}
		}
		puts("YES");
		for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++) putchar(ch[i][j]);
		return;
	}
	if(K&1) return puts("NO"),void();else puts("YES");
	for(int i=1;i<=n;i+=2) for(int j=1;j<=m;j+=2)
	{
		if(K)
		{
			K--,K--;
			ch[i][j]=ch[i][j+1]='a'+gt(i,j);
			ch[i+1][j]=ch[i+1][j+1]='e'+gt(i,j);
		}
		else
		{
			ch[i][j]=ch[i+1][j]='i'+gt(i,j);
			ch[i][j+1]=ch[i+1][j+1]='m'+gt(i,j);
		}
	}
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++) putchar(ch[i][j]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}