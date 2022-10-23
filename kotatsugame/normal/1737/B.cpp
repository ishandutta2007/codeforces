#include<iostream>
#include<cmath>
using namespace std;
long long f(long long N)
{
	if(N==0)return 0;
	long long n=sqrtl(N);
	while(n*n>N)n--;
	while((n+1)*(n+1)<=N)n++;
	long long ret=(n-1)*3;
	if(n*n<=N)ret++;
	if(n*(n+1)<=N)ret++;
	if(n*(n+2)<=N)ret++;
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		long long L,R;
		cin>>L>>R;
		cout<<f(R)-f(L-1)<<"\n";
	}
}