#include <iostream>
#include <cstdio>
using namespace std;
int t,k;
int a, b;
int mod=1000000007;
long long int r[200000];
long long int s[200000];
int main()
{
	scanf("%d %d",&t,&k);
	r[0]=1;
	s[0]=1;
	for(int i=1;i<=100000;i++)
	{
		r[i]=r[i-1];
		if(i>=k) r[i]=(r[i]+r[i-k])%mod;
		s[i]=(s[i-1]+r[i])%mod;
	}
	long long int res;
	for(int ind=0;ind<t;ind++)
	{
		scanf("%d %d",&a,&b);
		res=s[b]-s[a-1];
		res=res%mod;
		while(res<0) res+=mod;
		printf("%lld\n",res);
	}
	
	return 0;
}