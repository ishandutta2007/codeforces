#include<iostream>
using namespace std;
long long d,k,a,b,t,ans;
int main()
{
	cin>>d>>k>>a>>b>>t;
	if (d<=k) 
	{
		cout<<a*d<<endl;
		return 0;
	}
	if (t+a*k>b*k) ans=k*a+(d-k)*b;
	else 
	{
		ans=(d/k)*(t+a*k)-t;
		d=d%k;
		ans=ans+min(t+a*d,b*d);
	}
	cout<<ans<<endl;
	return 0;
}