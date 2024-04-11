// Lynkcat.
// Problem: E. ANDfinity
// URL: https://codeforces.com/contest/1689/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// -----------------------------------------------

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
#define N 2305
using namespace std;
int n,fa[N],b[N],a[N],ansa[N];
int sm[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	fa[x]=y;
	sm[y]|=sm[x];
	
}
int work()
{
	int res=0;
	for (int i=1;i<=n+30;i++)
		fa[i]=i,sm[i]=(i<=n)?b[i]:0;
	for (int i=1;i<=n;i++) a[i]=b[i];
	for (int i=1;i<=n;i++)
		for (int j=29;j>=0;j--)
			if ((a[i]>>j)&1)
				merge(i,n+1+j);
	map<int,int>Mp;
	for (int i=1;i<=n;i++) Mp[gf(i)]++;
	// cout<<"?"<<Mp.size()<<endl;
	if (Mp.size()==1) return res;
	for (auto [u,w]:Mp)
	{
		// cout<<"??"<<u<<","<<sm[u]<<endl;
		if (sm[u]%2==0)
		{
			for (int i=1;i<=n;i++)
				if (gf(i)==u)
				{
					a[i]++;
					res++;
					break;
				}
		}
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>b[i];
	int ans=0;
	for (int i=1;i<=n;i++)
		if (b[i]==0) b[i]++,ans++;
	int pp=work();
	for (int i=1;i<=n;i++) ansa[i]=a[i];
	// cout<<"?"<<pp<<" "<<bitset<15>(b[1])<<" "<<bitset<15>(b[2])<<endl;
	for (int i=1;i<=n;i++)
		if (b[i]>1)
		{
			b[i]--;
			int nowv=work()+1;
			if (nowv<pp) 
			{
				pp=nowv;
				for (int j=1;j<=n;j++) ansa[j]=a[j];
			}
			b[i]++;
		}
	cout<<pp+ans<<endl;
	for (int i=1;i<=n;i++) cout<<ansa[i]<<" ";
	cout<<endl;
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