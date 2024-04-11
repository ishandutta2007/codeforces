// Lynkcat.
// Problem: CF1687D Cute number
// URL: https://www.luogu.com.cn/problem/CF1687D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
#define N 2000005
using namespace std;
int n,a[N];
map<int,int>Mp;
int fa[N];
int col[N];
mt19937_64 rnd(time(0));
inline int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
inline int ins(int i,int x)
{
	return i*i<=x&&x<=((i*i+(i+1)*(i+1))/2);
}
inline int coll(int i)
{
	return i*i;
}
inline int colr(int i)
{
	return (i*i+(i+1)*(i+1))/2;
}
void BellaKira()
{
	cin>>n;
	int len=n;
	for (int i=1,nowi=1;i<=n;i++,nowi++)
	{
		cin>>a[nowi];
		// a[nowi]=rnd()%2000000+1;
		if (Mp.count(a[nowi])) nowi--,len--;
	}
	n=len;
	// sort(a+1,a+n+1);
	for (int j=sqrt(a[1]);j<=sqrt(a[1]);j++)
	{
		int l=j*j,r=(j*j+(j+1)*(j+1))/2;
		if (r<a[1]) continue;
		bool res=1;
		int mnl=0,mxr=inf;
		mnl=max(mnl,l-a[1]);
		mxr=min(mxr,r-a[1]);
		col[1]=j;
		for (int i=2;i<=n;i++)
		{
			int now=a[i]+mnl;
			col[i]=sqrt(now);
			if (!ins(col[i],now))
			{
				col[i]++;
			}
			mnl=max(mnl,coll(col[i])-a[i]);
			if (mxr<mnl) break;
			mxr=min(mxr,colr(col[i])-a[i]);
		}
		if (mxr<mnl) continue;
		if (!res) continue;
		cout<<mnl<<endl;
		return;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int j=sqrt(a[1])+1;j<=a[n];j++)
	{
		int l=j*j,r=(j*j+(j+1)*(j+1))/2;
		for(int i=gf(1);i<n;)
		{
			if (a[i]+j>=a[i+1]) fa[i]=i+1,i=gf(i);
			else i++,i=gf(i);
		}
		bool res=1;
		int mnl=0,mxr=inf;
		mnl=max(mnl,l-a[1]);
		mxr=min(mxr,r-a[1]);
		col[1]=j;
		int tt=0;
		// cout<<"?"<<j<<endl;
		for (int i=2;i<=n;i++)
		{
			// cout<<i<<" "<<gf(i)<<endl;
			int now=a[i]+mnl;
			col[i]=sqrt(now);
			if (!ins(col[i],now))
			{
				col[i]++;
			}
			mnl=max(mnl,coll(col[i])-a[i]);
			mxr=min(mxr,colr(col[i])-a[i]);
			mnl=max(mnl,coll(col[i])-a[gf(i)]);
			mxr=min(mxr,colr(col[i])-a[gf(i)]);
			i=gf(i);
			tt++;
		}
		// assert(tt*j<=2000000);
		// cout<<j<<"?"<<tt*j<<" "<<tt<<" "<<2000000/j<<endl;
		if (mxr<mnl) continue;
		if (!res) continue;
		cout<<mnl<<endl;
		return;
	}
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}