#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,i,j;cin>>n;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		int a=i,b=j;
		if (a%b==0 && a*b>n && a/b<n){cout<<a<<' '<<b;return 0;}
	}
	cout<<-1;
}