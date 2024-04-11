#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		ll n,b=2;cin>>n;
		while (n%2==0) n>>=1,b<<=1;
		if (n==1) puts("-1");else cout<<min(n,b)<<endl;
	}
}