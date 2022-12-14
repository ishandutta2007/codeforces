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
#define N 1000005
using namespace std;
int n;
int a[N],s[N];
void BellaKira()
{
	cin>>n;
	int cnt=0;
	poly g;
	for (int i=1;i<=2*n;i++)
	{
		string st;
		cin>>st;
		if (st=="+")
		{
			g.push_back(i);
		} else
		{
			int x;
			cin>>x;
			if (g.empty()) return cout<<"NO\n",void();
			a[i]=x;
			s[g.back()]=x;
			g.pop_back();
		}
	}
	multiset<int>S;
	for (int i=1;i<=2*n;i++)
		if (s[i])
		{
			S.insert(s[i]);
		} else
		{
			if ((*S.begin())!=a[i]) return cout<<"NO\n",void();
			S.erase(S.begin());
		}
	cout<<"YES\n";
	for (int i=1;i<=2*n;i++)
		if (s[i]) cout<<s[i]<<" ";
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}