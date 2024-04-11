#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,T,k,ans=0;
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();ans=0;
		while(m>0)ans+=m-n,m=m/10,n=n/10;
		printf("%d\n",ans);
	}
	return 0;
}