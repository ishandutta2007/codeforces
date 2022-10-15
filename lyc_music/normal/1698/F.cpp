// Lynkcat.
// Problem: F. Equal Reversal
// URL: https://codeforces.com/contest/1698/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
#define mod 998244353
#define int ll
#define N 2005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	if (a[1]!=b[1]||a[n]!=b[n]) return cout<<"NO"<<endl,void();
	vector<pa>ga,gb;
	for (int i=1;i<n;i++)
		ga.push_back(mp(min(a[i],a[i+1]),max(a[i],a[i+1])));
	for (int i=1;i<n;i++)
		gb.push_back(mp(min(b[i],b[i+1]),max(b[i],b[i+1])));
	sort(ga.begin(),ga.end());
	sort(gb.begin(),gb.end());
	if (ga!=gb) return cout<<"NO"<<endl,void();
	vector<pa>G;
	for (int i=2;i<n;i++)
		if (a[i]!=b[i])
		{
			int x=0;
			for (int j=i+1;j<=n;j++)
				if (a[j]==b[i-1]&&a[j-1]==b[i]) x=j;
			// for (int j=1;j<=n;j++) cout<<a[j]<<" ";
			// cout<<endl;
			if (x==0)
			{
				for (int j=i;j<=n;j++)
				{
					int bl=0;
					int now=0;
					for (int k=j+1;k<=n;k++)
					{
						if (a[k-1]==b[i-1]&&a[k]==b[i]) 
						{
							bl=1;
						}
						if (bl&&a[k]==a[j])
						{
							now=k;
							break;
						}
					}
					if (!now) continue;
					// cout<<"??"<<j<<" "<<now<<endl;
					G.push_back(mp(j,now));
					reverse(a+j,a+now+1);
					break;
				}
				for (int j=i+1;j<=n;j++)
					if (a[j]==b[i-1]&&a[j-1]==b[i]) x=j;	
			}
			G.push_back(mp(i-1,x));
			reverse(a+i-1,a+x+1);
		}
	cout<<"YES"<<endl;
	cout<<G.size()<<endl;
	for (auto u:G)
	{
		cout<<u.fi<<" "<<u.se<<endl;
	}
			
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}