#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	char ch=getchar();bool f=0;long long x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
long long n,m,a[100005];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
    	long long Max=-1e10,s=0,t=0;
    	m=read();for(int j=1;j<=m;j++)a[j]=read(),Max=max(Max,a[j]),s=max(s,Max-a[j]);
		while(s)
		{
			t++;s=s/2;
		}
    	printf("%lld\n",t);
	}
    return 0;
}