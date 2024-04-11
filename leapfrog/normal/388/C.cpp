//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,a[1005],at;ll sa,sb;
int main()
{
	for(read(n);n--;)
	{
		read(m);for(int x,i=1;i<=m;i++)
		{
			read(x);if((m&1)&&i==((m+1)>>1)) a[++at]=x;
			else if(i<=((m+1)>>1)) sa+=x;else sb+=x;
		}
	}
	sort(a+1,a+at+1,greater<int>());for(int i=1;i<=at;i++) if(i&1) sa+=a[i];else sb+=a[i];
	return printf("%lld %lld\n",sa,sb),0;
}