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
int n,m;char s[1005],t[1005];
inline void solve()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(j-i+1>m||s[j]!=t[j-i+1]) break;
			if(2*j-i>=m&&j-i+1==m) return puts("YES"),void();
			for(int k=j-1;k;k--)
			{
				if(s[k]!=t[j+j+1-k-i]) break;
				if(j+j+1-k-i==m) return puts("YES"),void();
			}
		}
	}
	puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}