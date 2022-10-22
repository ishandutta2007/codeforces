#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000000000000;
int t,A,B;
signed main()
{
	scanf("%lld",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%lld%lld",&A,&B);
		int num=0,cnt=0;
		for(int i=1;i<=12;i++)
		{
			num=num*10+9;
			if(num<=B) cnt++;
		}
		printf("%lld\n",cnt*A);
	}
	return 0;
}