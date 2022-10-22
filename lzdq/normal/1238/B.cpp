#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
inline void work()
{
	long long n=read(),r=read(),x[100001],bj=0,ans=0,faq=0;
	for(register long long i=1;i<=n;i++)x[i]=read();
	sort(x+1,x+1+n);
	for(register long long i=n;i>=1;i--)
	{
		if(x[i]-bj*r<=0)break;
		ans++,bj++,faq=x[i];
		while(x[i]==faq)i--;
		i++;
	}
	cout<<ans<<endl;
}
int main()
{
	int t=read();
	while(t--)work();
	return 0;
}