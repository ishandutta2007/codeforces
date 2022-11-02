#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a[maxn],ans,T;
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		if(n==m){puts("0 0");continue;}
		if(n<m)swap(n,m);ans=m/(n-m);
		printf("%lld %lld\n",n-m,min(m-ans*(n-m),(ans+1)*(n-m)-m));
	}
	return 0;
}