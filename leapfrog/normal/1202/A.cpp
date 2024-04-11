//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
char s[100005],t[100005];int n,m;
inline void solve()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	int st=0;for(int i=m;i;i--) if(t[i]=='0') st++;else break;
	int k=0;for(int i=n-st;i>=1;i--) if(s[i]=='0') k++;else break;
	printf("%d\n",k);
}
signed main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}