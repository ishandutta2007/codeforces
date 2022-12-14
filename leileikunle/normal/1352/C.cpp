#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k; cin>>n>>k;
		int cun = k/(n-1);
		int yu = k%(n-1);
		if(yu==0)
		{
			cout<<cun*n-1<<endl;
		}else{
			cout<<cun*n+yu<<endl;
		}
		
	}
}