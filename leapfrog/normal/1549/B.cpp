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
int n;char a[200005],b[200005],mt[200005];
inline void solve()
{
	read(n),scanf("%s%s",a+1,b+1);int rs=0;
	mt[0]=1;for(int i=1;i<=n;i++) mt[i]=0;
	for(int i=1;i<=n;i++) if(b[i]^48)
	{
		if(!mt[i-1]&&a[i-1]=='1') mt[i-1]=1,rs++;
		else if(!mt[i]&&a[i]=='0') mt[i]=1,rs++;
		else if(!mt[i+1]&&a[i+1]=='1') mt[i+1]=1,rs++;
	}printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}