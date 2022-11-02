//
#include<bits/stdc++.h>
#define int long long
using namespace std;const long long INF=1e6;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,k;char c[100005];
inline long long check(int a,int b) {return (a==0&&b==0)*INF+(b&&a*b*1ll>=0&&a%b==0);}
signed main()
{
	for(read(T);T--;)
	{
		read(n),read(k),scanf("%s",c+1);
		int tot=0,now=0;long long res=0;for(int i=1;i<=n;i++) tot+=c[i]=='0'?1:-1;
		for(int i=1;i<=n;i++) now+=c[i]=='0'?1:-1,res+=check(k-now,tot);
		printf("%lld\n",res>=INF?-1:res+!k);
	}
	return 0;
}