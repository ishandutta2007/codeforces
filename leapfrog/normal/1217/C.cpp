//Coded by Kamiyama_Shiki on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;char ch[N];int n;
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);int rs=0;
	for(int i=1,cnt=0;i<=n;i++) if(ch[i]=='0') cnt++;else
	{
		cnt++;for(int j=i+1,nw=1;j<=n;j++) {nw=nw<<1|(ch[j]^48),cnt++;if(nw<=cnt) rs++;else break;}
		cnt=0,rs++;
	}printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}