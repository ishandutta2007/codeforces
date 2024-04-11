#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n;cin>>n;
		if (n<=99)
		{
			cout<<n%10<<endl;
			continue;
		}
		else
		{
			int t=9;
			while (n) t=min(t,n%10),n/=10;
			cout<<t<<endl;
		}
	}
}