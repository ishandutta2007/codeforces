#include<iostream>
#include<cmath>
using namespace std;
long long n,k,cntf,cntt,ts;
int main()
{
	cin>>n>>k;
	ts=n;
	while(ts%5==0)
	{
		ts/=5;
		cntf++;
	}
	ts=n;
	while(ts%2==0)
	{
		ts/=2;
		cntt++;
	}
	n=n/pow(5,min(cntf,k));
	n=n/pow(2,min(cntt,k));
	cout<<n;
	for (int i=1;i<=k;i++) cout<<'0';
	cout<<endl;
	return 0;
}