#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int T,n,m,a,b,ans=0;
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read(),a=read(),b=read();ans=0;
		if(n>m)swap(n,m);if(a>b)swap(a,b);
		if(a==b){printf("%lld\n",n/a);continue;}
		int k=(m-n)/(b-a);
		if(n-a*k>0)ans+=k;
		else{printf("%lld\n",n/a);continue;}
		n=n-k*a,m=m-k*b;
		k=n/(a+b);ans+=2*k;n=n-(a+b)*k,m=m-(a+b)*k;
		if(n>=a&&m>=b)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}