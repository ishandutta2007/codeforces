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
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	string st,st1;
	cin>>n;
	cin>>st>>st1;
	for (auto &u:st)
		if (u=='B') u='G';
	for (auto &u:st1)
		if (u=='B') u='G';
	if (st==st1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
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