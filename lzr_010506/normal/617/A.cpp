#include<bits/stdc++.h>
using namespace std;
int main( )
{
long long  n,ans=0,i=5;
cin>>n;
while(n!=0)
{
	ans+=floor(n/i);
	n%=i;
	i--;
}
cout<<ans;
return 0;
}