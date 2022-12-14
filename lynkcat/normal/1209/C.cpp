#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int vis[N];
void BellaKira()
{
	int n;
	string st;
	cin>>n>>st;
	string x,y;
	for (int i=0;i<n;i++) vis[i]=0;
	string st1=st;
	sort(st1.begin(),st1.end());
	int l=0;
	for (int i=0;i<st1.size();i++)
	{
		while (l<n&&st[l]!=st1[i])
		{
			l++;
		}
		if (l>n) break;
		vis[l]=1;
		l++;
	}
	string st2="";
	for (int i=0;i<n;i++)
		if (!vis[i]) st2+=st[i];
	string st3=st2;
	sort(st3.begin(),st3.end());
	if (st3!=st2) cout<<"-\n";
	else 
	{
		for(int i=0;i<n;i++) cout<<(vis[i]^1)+1;
		cout<<'\n';
	}
	
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}