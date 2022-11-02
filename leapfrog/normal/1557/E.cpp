//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),bz=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    bz?x=-x:x;
}/*}}}*/
inline void solve()
{
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++)
	{
		printf("%d %d\n",i,i&1?j:9-j),fflush(stdout);
		string s;cin>>s;if(s=="Done") return;
	}
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++)
	{
		printf("%d %d\n",i,i&1?9-j:j),fflush(stdout);
		string s;cin>>s;if(s=="Done") return;
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}