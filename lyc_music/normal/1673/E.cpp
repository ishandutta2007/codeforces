// Lynkcat.
// Problem: E. Power or XOR?
// URL: https://codeforces.com/problemset/problem/1673/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define int ll
#define N 20000005
using namespace std;
int n,m,a[N];
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return (((x-y)&(y))==0);
}
int chk(int x,int y)
{
	if (x==0||y==0) return 1;
	return C(x-1,y);
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	poly ans((1<<20),0);
	for (int i=1;i<=n;i++)
	{
		int o=a[i];
		for (int j=i;j<=n;j++)
		{
			int tot=n-1-(i!=1)-(j!=n)-(j-i);
			int g=m-(i!=1)-(j!=n);
			// cout<<i<<" "<<j<<" "<<o<<" "<<tot<<" "<<g<<" "<<(1<<a[j])<<endl;
			if (g<=tot)
			{
				g=tot-g;
				if (chk(tot,g))
				{
					// cout<<"!"<<endl;
					ans[o]^=1;
				}
			}
			if (j==n) break;
			if (a[j+1]>20||o*(1<<a[j+1])>=(1<<20)) break;
			o=o*(1<<a[j+1]);
		}
	}
	while (ans.size()>1&&ans.back()==0) ans.pop_back();
	while (!ans.empty()) cout<<ans.back(),ans.pop_back();
	cout<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}