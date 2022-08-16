#include<cstdio>
#include<iostream>

using namespace std;

const long long p=1000000007;
const int MaxN=1000010;

long long k,w,ans;

long long A[MaxN],B[MaxN],F[MaxN];

long long calc(int x,int y)
{
	return A[x]*B[x-y]%p;
}

long long power(long long x,long long y)
{
	if (!y) return 1;
	long long t=power(x,y>>1);
	t=t*t%p;
	if (y&1) t=t*x%p;
	return t;
}

int main()
{
	cin>>k>>w;
	F[1]=1;
	for (int i=2;i<=k;++i)
		F[i]=p-p/i*F[p%i]%p;
	A[0]=B[0]=1;
	for (int i=1;i<=k;++i)
	{
		A[i]=A[i-1]*i%p;
		B[i]=B[i-1]*F[i]%p;
	}
	long long v=power(k,w-2);
	for (int t=1;t<=k;++t)
	{
		if (t<=w-1)
			(ans+=calc(k,t)*calc(k,t)%p*t%p*v)%=p;
		else
			(ans+=calc(k,t)*calc(k-t+w-1,w-1)%p*w)%=p;
		if (t==k) break;
		v=v*F[k]%p;
		if (t+1<=w-1)
			(ans+=calc(k,t)*calc(k,t+1)%p*t%p*v)%=p;
		else
			(ans+=calc(k,t)*calc(k-t+w-2,w-1)%p*(w-1))%=p;
	}
	cout<<ans<<endl;
	return 0;
}