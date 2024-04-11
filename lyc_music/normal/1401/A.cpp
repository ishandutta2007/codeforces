#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>k;
		if (n>=k)
		{
			cout<<abs(n%2-k%2)<<endl;
		} else cout<<k-n<<endl;
	}
}