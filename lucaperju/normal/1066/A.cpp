#include <iostream>
const int N=10000000;
using namespace std;
long long rez[10000003];
int fctpr[10000003],prime[10000003],cur[100],ciur[10000003];
int main()
{
	int t,a,b,c,d;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b>>c>>d;
	    a/=b;
	    a-=d/b;
	    a+=(c-1)/b;
	    cout<<a<<'\n';
	}
}