//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int Q,s;long long n;
int main()
{
	for(read(Q);Q--;)
	{
		read(n),read(s);int cnt=0;long long x=n,ans=0,rw=0;
		while(x) cnt+=x%10,x/=10;
		if(cnt<=s) {puts("0");continue;}
		for(long long res=1;cnt>s&&res<n;res*=10)
		{
			int c=n/res%10;if(c==0) continue;
			ans+=(10-c)*res,n+=(10-c)*res,cnt=0,rw=n;
			while(rw) cnt+=rw%10,rw/=10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}