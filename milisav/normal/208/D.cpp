#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long int p[500];
long long int sum=0;
long long int a,b,c,d,e;
long long int a1(0),b1(0),c1(0),d1(0),e1(0);
long long int a2,b2,c2,d2,e2;
int main()
{
	cin>>n;
	bool f;
	for(int i=0;i<n;i++) cin>>p[i];
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<n;i++)
	{
		sum+=(p[i]);
		f=true;
		e2=sum/e;
		sum-=e2*e;
		e1+=e2;
		d2=sum/d;
		sum-=d2*d;
		d1+=d2;
		c2=sum/c;
		sum-=c2*c;
		c1+=c2;
		b2=sum/b;
		sum-=b2*b;
		b1+=b2;
		a2=sum/a;
		sum-=a2*a;
		a1+=a2;
	}
	cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<" "<<e1<<endl;
	cout<<sum<<endl;
	return 0;
}