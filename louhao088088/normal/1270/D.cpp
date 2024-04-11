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
int n,m,T,x,s[5005],k,y,ans,sum,sum1,Max=0;
signed main()
{
	n=read();k=read();
	for(int i=1;i<=k+1;i++)
	{
		cout<<"? ";
		for(int j=1;j<=k+1;j++)
			if(i==j)continue;
			else cout<<j<<" ";cout<<endl;
		fflush(stdout);
		x=read(),y=read();
		s[x]++;if(y>Max)ans=x,Max=y;
	}
	cout<<"! "<<s[ans]<<endl;fflush(stdout);exit(0);
	return 0;
}