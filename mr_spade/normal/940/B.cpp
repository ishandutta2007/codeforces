#include<cstdio>
typedef long long ll;
ll n,k,A,B;
ll res=0;
signed main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&A,&B);
	if(k==1)
		return printf("%I64d\n",(n-1)*A),0;
	while(n>1)
		if(n<k)
		{
			res+=(n-1)*A;
			n=1;
		}
		else if(n%k==0)
		{
			if((n-n/k)*A<B)
			{
				res+=(n-1)*A;
				n=1;
			}
			else
				res+=B,n/=k;
		}
		else
		{
			res+=(n-n/k*k)*A;
			n=n/k*k;
		}
	printf("%I64d\n",res);
	return 0;
}