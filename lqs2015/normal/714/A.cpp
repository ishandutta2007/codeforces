#include<iostream>
using namespace std;
long long l1,r1,l2,r2,k,ans,s,e;
int main()
{
	cin>>l1>>r1>>l2>>r2>>k;
	s=max(l1,l2);
	e=min(r1,r2);
	ans=e-s+1;
	if (k>=s && k<=e) ans--;
	if (ans<0) ans=0;
	cout<<ans<<endl;
	return 0;
 }