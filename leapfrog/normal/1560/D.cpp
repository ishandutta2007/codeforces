#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
char ch[105],fg[105];int n;
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	int rs=1e9;for(int i=0;i<=60;i++)
	{
		ll x=1ll<<i;int l=0;for(;x;x/=10) fg[++l]=x%10+'0';
		reverse(fg+1,fg+l+1);int f=1;
		for(int j=1;j<=n;j++) if(f<=l&&fg[f]==ch[j]) f++;
		rs=min(rs,l+n-f-f+2);
	}printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}