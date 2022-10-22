#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,l,r,m;
int check(int p)
{
	int d=abs(m-p);
	int s=abs(r-l);
	if(d<=s) return 1;
	return 0; 
}
signed main()
{
	scanf("%lld",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%lld%lld%lld",&l,&r,&m);
		for(int a=l;a<=r;a++)
		{
			int p=m/a;
			p*=a;
			if(p!=0&&check(p)) 
			{
				printf("%lld %lld %lld\n",a,r,r+(p-m));
				break;
			}			
			else if(check(p+a))
			{
				printf("%lld %lld %lld\n",a,l,l+p+a-m);
				break;
			}
		}
	}
}