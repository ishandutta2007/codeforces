#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

int DP[mn], rem[mn]; //DP[i]*T[i]+mcd[i];
int V[mn], T[mn], mcdT[mn];
int n;

int CNP(int u, int l, int r)
{
	if (V[u]>=mcdT[r]-mcdT[u-1]) return r;
	if (V[u]<mcdT[l]-mcdT[u-1]) return l-1;
	
	int m=(l+r)/2;
	
	if (V[u]>=mcdT[m]-mcdT[u-1]) return CNP(u, m+1, r);
	else return CNP(u, l, m);
}

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>V[i];
		DP[i]=0;
		rem[i]=0;
	}
	for (int i=1; i<=n; i++) cin>>T[i];
	
	mcdT[0]=0;
	for (int i=1; i<=n; i++) mcdT[i]=mcdT[i-1]+T[i];
	
	for (int i=1; i<=n; i++)
	{
		DP[i]++;
		int r=CNP(i, i, n);
		
		DP[r+1]--;
		rem[r+1]+=(V[i]-(mcdT[r]-mcdT[i-1]));
	}
	
	for (int i=2; i<=n; i++) DP[i]+=DP[i-1];
//	for (int i=1; i<=n; i++) cout<<DP[i]<<" ";
//	cout<<"\n";
//	for (int i=1; i<=n; i++) cout<<T[i]<<" ";
//	cout<<"\n";
	for (int i=1; i<=n; i++) cout<<DP[i]*T[i]+rem[i]<<" ";
}