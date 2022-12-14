#include<iostream>
#include<cmath>
using namespace std;
long long n,m,ans;
int main()
{
	cin>>m;
	n=2*m-2;
	ans=2*4*3*pow(4,n-m-1)+(n-m-1)*4*3*3*pow(4,n-m-2);
	cout<<ans<<endl;
	return 0;
}