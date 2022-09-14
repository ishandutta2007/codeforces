#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
	int n;double n1,n2;cin>>n>>n1>>n2;
	int a[100001];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,[](const double a,const double b){return a>b;});
	double sum1=0,sum2=0;
	if(n1>n2)
	{
		int sto=n2;
		n2=n1;
		n1=sto;
	}
	for(int i=0;i<n1;i++)sum1+=(double)a[i];
	for(int i=n1;i<n1+n2;i++)sum2+=(double)a[i];
	cout<<fixed<<setprecision(6)<<sum1/n1+sum2/n2<<endl;
	return 0;
}