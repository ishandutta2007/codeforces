//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n,m;char a[55],b[55];
inline void solve()
{
	scanf("%s%s",a+1,b+1),n=strlen(a+1),m=strlen(b+1);
	for(int ln=min(n,m);ln;ln--)
	{
		for(int i=1;i+ln-1<=n;i++) for(int j=1,fg=0;j+ln-1<=m;j++,fg=0)
		{
			for(int k=1;k<=ln;k++) if(a[i+k-1]!=b[j+k-1]) fg=1;
			if(!fg) return printf("%d\n",n+m-ln*2),void();
		}
	}
	printf("%d\n",n+m);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}