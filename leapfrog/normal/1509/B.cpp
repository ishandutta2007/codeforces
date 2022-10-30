//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n;char ch[100005];
inline void solve()
{
	read(n),scanf("%s",ch+1);int na,nb;
	na=0,nb=0;for(int i=1;i<=n;i++)
		{na+=ch[i]=='T',nb+=ch[i]=='M';if(na<nb) return puts("NO"),void();}
	na=0,nb=0;for(int i=n;i>=1;i--)
		{na+=ch[i]=='T',nb+=ch[i]=='M';if(na<nb) return puts("NO"),void();}
	if(na!=nb+nb) return puts("NO"),void();else puts("YES");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}