#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int T;
LL n,v1,v2,s1,s2,ans;
int main()
{
	ans=0;
	cin>>n>>v1>>v2>>s1>>s2;
	for(LL i=0;i<=100000;i++)
	{
		if(s1*i<=n) ans=max(ans,v1*i+(n-s1*i)/s2*v2);
		if(s2*i<=n) ans=max(ans,v2*i+(n-s2*i)/s1*v1);
	}
	cout<<ans<<endl;
	return 0;
}