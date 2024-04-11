//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,tn[26];char ch[1005];
inline void solve()
{
	read(n);for(int i=0;i<26;i++) tn[i]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);int m=strlen(ch+1);
		for(int j=1;j<=m;j++) tn[ch[j]-'a']++;
	}
	char fg=0;for(int i=0;i<26;i++) fg|=!!(tn[i]%n);
	puts(fg?"NO":"YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}