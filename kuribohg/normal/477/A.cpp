#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
LL a,b,ans;
int main()
{
	cin>>a>>b;
	for(LL r=1;r<b;r++)
	{
		LL X=(1+a)*a/2LL;
		X%=MOD;
		ans=(ans+((a*r%MOD)+(((X*r)%MOD*b)%MOD))%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}