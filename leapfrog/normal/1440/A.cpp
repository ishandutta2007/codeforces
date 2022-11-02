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
const int N=1000005;
int n,a,b,x;char ch[N];
inline void solve()
{
	read(n,a,b,x),scanf("%s",ch+1);
	a=min(a,x+b),b=min(b,x+a);int rs=0;
	for(int i=1;i<=n;i++) rs+=(ch[i]&1?b:a);
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}