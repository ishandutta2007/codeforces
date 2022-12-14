#include<iostream>
using namespace std;
long long n,a,b,p,q,ans,mul;
long long gsc(long long a,long long b)
{
	if (b==0) return a;
	return gsc(b,a%b);
}
int main()
{
	cin>>n>>a>>b>>p>>q;
	mul=a*b/gsc(a,b);
	if (p>q) ans=(n/a)*p+(n/b-n/mul)*q;
	else ans=(n/b)*q+(n/a-n/mul)*p;
	cout<<ans<<endl;
	return 0;
}