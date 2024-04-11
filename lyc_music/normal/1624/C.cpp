// Lynkcat.
// Problem: C. Division by Two and Permutation
// URL: https://codeforces.com/contest/1624/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// -----------------------------------------------

//~~
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
#define N 10005
using namespace std;
int n,a[N];
int vis[N];
int f[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int nn=n;
	for (int i=1;i<=n;i++)
		vis[i]=0;
    for(int i=1;i<=nn;i++){
        if(a[i]>n){
            a[++nn]=a[i]/2;
        }else if(vis[a[i]]){
            a[++nn]=a[i]/2;
        }else if(a[i]){
            vis[a[i]]=1;
        }
    }
    int cnt=0;
	for (int i=1;i<=n;i++)cnt+=vis[i];
    puts(cnt==n?"YES":"NO");
			
}
signed main()
{
	// IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}