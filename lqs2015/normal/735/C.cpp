#include<iostream>
#include<cmath>
using namespace std;
long long n,f[111];
int main()
{
	cin>>n;
	f[0]=1;f[1]=2;
	for (int i=2;i<=100;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if (n>=f[i-1] && n<f[i]) 
		{
			cout<<i-1<<endl;
			return 0;
		}
	}
	return 0;
}