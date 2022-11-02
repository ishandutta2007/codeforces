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
const int N=200005;int n;char ch[N];
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);int rs=0,tp;
	tp=0;for(int i=1;i<=n;i++) if(ch[i]=='(') tp++;else if(ch[i]==')'&&tp) tp--,rs++;
	tp=0;for(int i=1;i<=n;i++) if(ch[i]=='[') tp++;else if(ch[i]==']'&&tp) tp--,rs++;
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}