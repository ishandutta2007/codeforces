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
int T;long long n;
int main()
{
	for(read(T);T--;)
	{
		read(n);long long r=0;
		while(n)
		{
			if(n==4) ++++r,n>>=1;
			else if(n&1) r++,n--;
			else if((n>>1)&1) r+=n>>1,n>>=1;
			else r++,n--;
			if(!n) break;
			if(n==4) n>>=1;
			else if(n&1) n--;
			else if((n>>1)&1) n>>=1;
			else n--;
			// cout<<n<<" "<<r<<endl;
		}
		printf("%lld\n",r);
	}
	return 0;
}