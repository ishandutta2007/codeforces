#include<iostream>
#include<cmath>
using namespace std;
long long a[111111];
double pp;
bool f;
bool ss(int n)
{
	for (int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		pp=sqrt(a[i]);
		if ((int)pp==pp && pp!=1)
		{
			f=ss(pp);
			if (!f) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}