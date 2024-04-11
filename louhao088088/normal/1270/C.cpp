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
int n,m,T,x,s[105],l,ans[105],Ans,sum,sum1;
signed main()
{
	T=read();
	while(T--)
	{
		//cout<<T<<endl;
		n=read();sum1=sum=0;
		for(int i=1;i<=n;i++)
		{
			x=read();sum+=x;sum1^=x;
		}cout<<2<<endl;
		cout<<sum1<<" "<<sum+sum1<<endl;
	}
	return 0;
}