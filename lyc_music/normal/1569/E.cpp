// Lynkcat.
// Problem: E. Playoff Restoration
// URL: https://codeforces.com/contest/1569/problem/E
// Memory Limit: 512 MB
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
#define N 55
using namespace std;
int n,A,h,pw[N];
int dep[N];
map<int,int>ji,huo;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int dfs(int stat,int k,int l,int r,int adep,int dp)
{
	if (l==r) return l;
	int mid=l+(r-l)/2;
	int x=dfs(stat,k<<1,l,mid,adep,dp+1);
	int y=dfs(stat,k<<1|1,mid+1,r,adep,dp+1);
	if ((stat>>(k-1))&1)
	{
		dep[x]=dp+1;
		return y;
	}
	dep[y]=dp+1;
	return x;
}
inline int getval(int j)
{
	if (dep[j]==0)
			{ return 1;
			}
			else if (dep[j]==1) return 2;
			else return (1ll<<(dep[j]-1))+1;
}
inline int calc(int l,int r)
{
	int res=0;
	for (int j=l;j<=r;j++)
		res=(res+j*pw[getval(j)]%mod)%mod;
	return res;
}
void BellaKira()
{
	cin>>n>>A>>h;
	for (int i=1;i<=(1<<n);i++)
		pw[i]=quickPower(A,i);
	
	if (n<=4)
	{
		int tot=(1<<n)-1;
		for (int i=0;i<(1<<tot);i++)
		{
			for (int j=1;j<=(1<<n);j++) dep[j]=0;
			int now=dfs(i,1,1,(1<<n),n,0);
			int vv=calc(1,(1<<n));
			if (vv==h)
			{
				for (int j=1;j<=(1<<n);j++)
					if (dep[j]==0)
					{
						cout<<1<<" ";
					}
					else if (dep[j]==1) cout<<2<<" ";
					else if (dep[j]>1) cout<<(1ll<<(dep[j]-1))+1<<" ";
				return;
			}
		}
		cout<<-1<<endl;
		return;
	}
	int tot=(1<<4)-1;
	for (int i=0;i<(1<<tot);i++)
	{
		for (int j=1;j<=(1<<4);j++) dep[j]=0;
		int now=dfs(i,1,1,(1<<4),4,0);
		int vv=0;
		
		for (int j=1;j<=(1<<4);j++) dep[j]++;
		vv=calc(1,(1<<4));
		ji[vv]=i;
		
		dep[now]--;
		vv=calc(1,(1<<4));
		huo[vv]=i;
	}
	for (int i=0;i<(1<<tot);i++)
	{
		for (int j=(1<<4)+1;j<=(1<<5);j++) dep[j]=0;
		int now=dfs(i,1,(1<<4)+1,(1<<5),4,0);
		int l=(1<<4)+1,r=(1<<5);
		int vv=0;
		
		for (int j=l;j<=r;j++) dep[j]++;
		dep[now]--;
		vv=calc(l,r);
		if (ji.count((h-vv+mod)%mod))
		{
			int nowp=ji[(h-vv+mod)%mod];
			// cout<<"?"<<nowp<<endl;
			for (int j=1;j<=(1<<4);j++) dep[j]=0;
			int now=dfs(nowp,1,1,(1<<4),4,0);
			for (int j=1;j<=(1<<4);j++) dep[j]++;
			for (int j=1;j<=(1<<5);j++)
				cout<<getval(j)<<" ";
			cout<<endl;
			return;
		}
		
		dep[now]++;
		vv=calc(l,r);
		if (huo.count((h-vv+mod)%mod))
		{
			int nowp=huo[(h-vv+mod)%mod];
			// cout<<"?"<<nowp<<endl;
			for (int j=1;j<=(1<<4);j++) dep[j]=0;
			int now=dfs(nowp,1,1,(1<<4),4,0);
			for (int j=1;j<=(1<<4);j++) dep[j]++;
			dep[now]--;
			for (int j=1;j<=(1<<5);j++)
				cout<<getval(j)<<" ";
			cout<<endl;
			return;
		}
	}
		cout<<-1<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}