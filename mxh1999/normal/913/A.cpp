#include<bits/stdc++.h>
using namespace std;

int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if (n>60)
	{
		cout<<m<<endl;
		return 0;
	}	else
	{
		long long ans=m;
		cout<<ans%(1LL<<n)<<endl;
	}
	return 0;
}