//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;char ch[5];
inline void solve()
{
	scanf("%s",ch+1);int n=strlen(ch+1),d=ch[1]-'0';
	printf("%d\n",10*(d-1)+n*(n+1)/2);
}
int main() {for(read(T);T--;) solve();return 0;}