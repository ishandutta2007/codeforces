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
#define N 200005
using namespace std;
int n;
string st;
int nxt[N];
int solve(int l,int r)
{
	if (l>r) return 0;
	// cout<<l<<" "<<r<<endl;
	if (l+1==r)
	{
		return 1;
	}
	int mid=nxt[l];
	if (mid==r)
	{
		return 1+solve(l+1,r-1);
	}
	return solve(l+1,mid-1)+solve(mid+1,r);
}
void BellaKira()
{
	cin>>n;
	cin>>st;
	st=' '+st;
	n=2*n;
	poly g;
	for (int i=1;i<=n;i++)
	{
		if (st[i]=='(') g.push_back(i);
		else
		{
			nxt[g.back()]=i;
			nxt[i]=g.back();
			// cout<<g.back()<<" "<<i<<endl;
			g.pop_back();
		}
	}
	cout<<solve(1,n)<<endl;
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