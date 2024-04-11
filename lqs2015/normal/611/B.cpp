#include<iostream>
#include<cmath>
using namespace std;
long long m,n,k,ans,a,b;
int main()
{
	cin>>m>>n;
	for (int i=1;i<=60;i++)
	{
		for (int j=1;j<i;j++)
		{
			a=pow(2,i);b=pow(2,j-1);
			k=a-1-b;
			if (k>=m && k<=n) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}