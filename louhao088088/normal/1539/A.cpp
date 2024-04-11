#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a,b,c;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a=read(),b=read(),c=read();
		int num=0,ans=0;num=c/b;
		if(num>a)ans=a*(a-1)/2;
		else 
		{
			num=c/b;ans=(a-num)*num;
			ans=ans+num*(num-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}