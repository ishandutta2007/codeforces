#include<cstdio> 
#include<iostream>
using namespace std;
int n,ans;
inline long long read()
{
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read();
	for(long long i=1;i<=n;++i)
	{
		long long cnt=read(),tot=read();
		long long x=tot%cnt,tmp=tot/cnt;
		ans=((tmp+1)*(tmp+1)*x)+(tmp*tmp*(cnt-x));
		cout<<ans<<endl;
	}
	return 0;
}