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
int n,m,a[maxn],ans,T,sum;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();sum=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		sum=sum%n;cout<<(n-sum)*sum<<endl;
	}
	return 0;
}