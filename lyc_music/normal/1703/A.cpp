// Lynkcat.
// Problem: A. YES or YES?
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/A
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
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	string st;
	cin>>st;
	for (int i=0;i<st.size();i++)
		if (st[i]>='a'&&st[i]<='z') st[i]=st[i]-'a'+'A';
	if (st=="YES") cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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