#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;ll n,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%lld",&n);
		while(!(n%2)) n/=2,++ans;while(!(n%3)) n/=3,ans+=2;while(!(n%5)) n/=5,ans+=3;
		if(n!=1) ans=-1;printf("%d\n",ans);
	}
}