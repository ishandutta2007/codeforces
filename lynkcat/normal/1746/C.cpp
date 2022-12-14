// Problem: C. Permutation Operations
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.ml/contest/1746/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define N 100005
using namespace std;
int n,a[N],s[N],f[N];
int b[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],b[a[i]]=i;
	for (int i=1;i<=n;i++) cout<<b[n-i+1]<<" ";
	cout<<'\n';
	// for (int i=1;i<=n;i++)
		// s[i]+=i;
	// for (int i=1;i<=n;i++)
		// s[i]=s[i-1]+s[i],f[i]=a[i]+s[i];
	// int w=0;
	// for (int i=1;i<=n;i++)
		// for (int j=i+1;j<=n;j++)
			// w+=f[j]<f[i];
	// cout<<"?"<<w<<endl;
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}