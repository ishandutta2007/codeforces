// Lynkcat.
// Problem: A. Two 0-1 sequences
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
// #define N 
using namespace std;
int n,m;
string st,st1;
void BellaKira()
{
	cin>>n>>m;
	cin>>st>>st1;
	reverse(st.begin(),st.end());
	reverse(st1.begin(),st1.end());
	int x=0,y=0;
	if (st.back()=='1') x=1;
	else y=1;
	st.pop_back();
	while (st.size()>=st1.size())
	{
		x|=st.back()=='1';
		y|=st.back()=='0';
		st.pop_back();
	}
	string st2=st1;
	st2.pop_back();
	if (st==st2&&((st1.back()=='0')&&y||(st1.back()=='1')&&x)) cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
		
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