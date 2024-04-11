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
// #define N 
using namespace std;
int n;
string st;
void BellaKira()
{
	cin>>n;
	cin>>st;
	st=' '+st;
	int ans=0;
	priority_queue<int>q;
	for (int i=1;i<=n;i++)
	{
		int x=0;
		if (st[i]=='L') 
		{
			ans+=i-1;
			q.push(max(0ll,(n-i)-(i-1)));
		}
		else
		{
			ans+=n-i;
			q.push(max(0ll,(i-1)-(n-i)));
		}
	}
	for (int i=1;i<=n;i++)
	{
		ans+=q.top();
		q.pop();
		cout<<ans<<" ";
	}
	cout<<endl;
		
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