#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,i,ans;cin>>n;ans=(2*n+1)/3;
	cout<<(2*n+1)/3<<endl;
	if (ans%2==0) {cout<<n<<' '<<n<<endl;ans--;n--;}
	if (ans&1)
	{
		int u=ans/2;
		for (i=1;i<=u;i++) cout<<i<<' '<<u-i+1<<endl;
		for (i=1;i<=u+1;i++)
		{
			cout<<n-i+1<<' '<<n-u+i-1<<endl;
		}
	}
}