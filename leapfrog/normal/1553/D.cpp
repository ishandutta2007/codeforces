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
int n,m;char s[1000005],t[100005];
inline void solve()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=1,j=1,ls=0;i<=n;i++)
	{
		if(s[i]==t[j]&&(i-ls)&1) ls=i,j++;
		if(j==m+1) {if(!((n-i)&1)) return puts("YES"),void();else break;}
	}
	for(int i=1,j=1,ls=1;i<=n;i++)
	{
		if(s[i]==t[j]&&(i-ls)&1) ls=i,j++;
		if(j==m+1) {if(!((n-i)&1)) return puts("YES"),void();else break;}
	}
	puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}