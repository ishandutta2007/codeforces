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
int n,q,s[300005];char ch[3000005];
inline void solve()
{
	read(n,q),scanf("%s",ch+1);
	//for(int i=1;i<=n;i++) if(i&1) printf("%c",ch[i]);else printf("%c",ch[i]^'+'^'-');
	for(int i=1;i<=n;i++) s[i]=s[i-1]+((ch[i]=='+')^(i&1)?-1:1);
	for(int i=1,l,r;i<=q;i++)
	{
		read(l,r);if((r-l+1)&1) {puts("1");continue;}
		if(s[r]-s[l-1]) puts("2");else puts("0");
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}