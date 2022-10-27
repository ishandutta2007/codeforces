#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second
#define zin cin

int n,row[mn], col[mn];


signed main()
{
#ifndef zin
	ifstream zin;
	zin.open(FLN".inp", ios::in);
#endif
	zin>>n;
	int cnod=0;
	
	for (int i=1; i<=n; i++)
	{
		cout<<"? 1 "<<i<<" "<<n<<" "<<i<<endl;
		cin>>col[i];
		cnod+=col[i]%2;
	}
	for (int i=1; i<n; i++)
	{
		cout<<"? "<<i<<" 1 "<<i<<" "<<n<<endl;
		cin>>row[i];
		cnod+=row[i]%2;
	}
	row[n]=2-cnod;
	
	vector <pii> ans={};
	for (int i=1; i<=n; i++) if (col[i]%2==1)
	{
		int l=1, r=n;
		while (r>l)
		{
			int mid=(l+r)/2, t;
			
			cout<<"? 1 "<<i<<" "<<mid<<" "<<i<<endl;
			cin>>t;
			if (t%2==0) l=mid+1;
			else r=mid;
		}
		
		ans.push_back({l, i});
	}
	
	
	if (ans.size()<2)
	{
		for (int i=1; i<=n; i++) if (row[i]%2==1)
		{
			int l=1, r=n;
			while (r>l)
			{
				int mid=(l+r)/2, t;
				
				cout<<"? "<<i<<" 1 "<<i<<" "<<mid<<endl;
				cin>>t;
				if (t%2==0) l=mid+1;
				else r=mid;
			}
			
			ans.push_back({i, l});
		}
	}
	
	cout<<"! "<<ans[0].XX<<" "<<ans[0].YY<<" "<<ans[1].XX<<" "<<ans[1].YY<<endl;
	exit(0);
}