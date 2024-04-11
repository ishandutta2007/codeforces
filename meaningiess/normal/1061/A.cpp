#include<iostream>
using namespace std;
int main()
{
	int a,b,i,ans=0;cin>>a>>b;
	for (i=a;i;i--) if (b>=i) ans+=b/i,b%=i;cout<<ans;
}