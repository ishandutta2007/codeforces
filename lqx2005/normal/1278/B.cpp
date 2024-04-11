#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=50000;
int t,a,b;
int num[maxn+5];
signed main()
{
	for(int i=1;i<=maxn;i++) num[i]=i*(i+1)/2;
	scanf("%lld",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b) swap(a,b);
		b-=a;
		if(b==0) printf("0\n");
		else
		{
			int pos=lower_bound(num+1,num+maxn+1,b)-num;
			if(num[pos]%2!=b%2)
			{
				if(pos%2) pos+=2;
				else pos++;
			}
			printf("%lld\n",pos);
		}
	}
	return 0;
}