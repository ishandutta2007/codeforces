#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[11][11],b[100];
signed main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n; cin>>m>>n;
		int fu = 0;
		int sum = 0,minn = 100;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				b[abs(a[i][j])]++;
				sum += abs(a[i][j]);
				if(a[i][j]<0) fu++;
				if(abs(minn)>abs(a[i][j])) minn = a[i][j];
			}
		}
		if(fu%2) cout<<sum-2*abs(minn)<<endl;
		else{
			cout<<sum<<endl;
		}
	}
}