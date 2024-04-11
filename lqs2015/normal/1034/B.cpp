#include<iostream>
#include<cstdio>
using namespace std;
int a[11],b[111][111];
long long n,m,ans;
int main()
{
	a[1]=1;a[2]=2;a[3]=3;a[4]=2;a[5]=1;a[0]=0;
	b[2][2]=4;b[2][3]=2;b[2][7]=2;
	cin>>n>>m;
	if (n>m) swap(n,m);
	if (n==1)
	{
		cout<<n*m-a[m%6]<<endl;
		return 0;
	}
	if (m>20)
	{
		if ((n&1) && (m&1)) cout<<n*m-1<<endl;
		else cout<<n*m<<endl;
		return 0;
	}
	ans=n*m;
	if ((n&1) && (m&1)) ans--;
	ans-=b[n][m];
	cout<<ans<<endl;
	return 0;
}