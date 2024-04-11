#include<iostream>
using namespace std;
int main()
{
	long long n,k,s;
	cin>>n>>k;
	s=n/2+n%2;
	if (k<=s) cout<<2*k-1;
	else cout<<2*(k-s);
	return 0;
}