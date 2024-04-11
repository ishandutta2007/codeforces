#include<iostream>
#define ll __int64
using namespace std;

int main()
{
	ll n,m,a;
	cin>>n>>m>>a;
	cout<<((n+a-1)/a)*((m+a-1)/a)<<endl;
	return 0;
}