#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005],b[100005]; 
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,d; cin>>n>>d;
		int sum = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i] = a[i];
			sum += a[i];
		}
		while(1)
		{
			bool shi = false;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%d==0)
				{
					sum += b[i];
					a[i] /= d;
				}else{
					shi = true;
					break;
				}
			}
			if(shi) break;
		}
		cout<<sum<<endl;
	}
 }