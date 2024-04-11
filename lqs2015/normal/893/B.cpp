#include<iostream>
#include<cmath>
using namespace std;
int n,k,ans;
int main()
{
	cin>>n;
	k=1;
	for (int i=1;i<=100000;i++)
	{
		if (k>n) break;
		k=(pow(2,i)-1)*pow(2,i-1);
		if (n%k==0) ans=k;
	}
	cout<<ans<<endl;
	return 0;
}