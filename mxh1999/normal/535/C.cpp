#include<bits/stdc++.h>

typedef long long ll;

const int MAXN=100010;
using namespace std;
ll a,b,n;
ll calc(int k)
{
	return (ll)a+(k-1)*b;
}
ll sum(int x,int y)
{
	return (calc(x)+calc(y))*(y-x+1)/2;
}
int main()
{
	ll l,t,m;
	scanf("%I64d%I64d%I64d",&a,&b,&n);
	while(n--)
	{
		scanf("%I64d%I64d%I64d",&l,&t,&m);
		if(calc(l)>t) puts("-1");
		else
		{
			ll L=l,R=(t-a)/b+1,mid;
			while(L<=R) {
				mid=L+(R-L)/2;
				if(sum(l,mid)<=(ll)t*m) L=mid+1;
				else R=mid-1;
			}
			printf("%I64d\n",L-1);
		}
	}
	return 0;
}