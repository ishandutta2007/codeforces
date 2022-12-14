// Lynkcat.
// Problem: A. Till I Collapse
// Contest: Codeforces - 10.9(1)
// URL: https://codeforces.com/gym/403085/problem/A
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
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 100005
using namespace std;
int tot;
mt19937_64 rnd(time(0));
int tr[N*20],lson[N*20],rson[N*20];
int n,a[N];
int lst[N];
int rt[N];
inline void pushup(int k)
{
	tr[k]=tr[lson[k]]+tr[rson[k]];
}
void update(int &rt,int x,int l,int r,int L)
{
	rt=++tot;
	tr[rt]=tr[x],lson[rt]=lson[x],rson[rt]=rson[x];
	if (l==r)
	{
		tr[rt]++;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(lson[rt],lson[x],l,mid,L);
	else update(rson[rt],rson[x],mid+1,r,L);
	pushup(rt);
}
inline int query(int x,int y,int l,int r,int L,int R)
{
	if (L>R) return 0;
	if (!x&&!y) return 0;
	if (L<=l&&r<=R) return tr[y]-tr[x];
	int mid=l+(r-l)/2;
	int res=0;
	if (L<=mid) res+=query(lson[x],lson[y],l,mid,L,R);
	if (R>mid) res+=query(rson[x],rson[y],mid+1,r,L,R);
	return res;
}
void BellaKira()
{
	cin>>n;
// 	n=100000;
	for (int i=1;i<=n;i++)
	{
// 		a[i]=rnd()%n+1;
		cin>>a[i];
		update(rt[i],rt[i-1],0,n-1,lst[a[i]]);
		lst[a[i]]=i;
	}
	int Ans=0;
	for (int i=1;i<=n;i++)
	{
		int now=1;
		int ans=0;
		while (now<=n)
		{
			int sm=0;
			int r=now-1;
			for (int j=now+i-1;;j+=i)
			{
				int nr=min(j,n);
				if (query(rt[r],rt[nr],0,n-1,0,now-1)+sm<=i)
				{
					sm+=query(rt[r],rt[nr],0,n-1,0,now-1);
					r=nr;
					if (r==n) break;
				} else
				{
					// cout<<now<<" "<<r<<" "<<sm<<" "<<nr<<" "<<" "<<
					// query(rt[r-1],rt[nr],0,n-1,0,now-1)<<" "<<sm<<endl;
					int L=r+1,R=nr;
					int pos=r;
					while (L<=R)
					{
						int mid=(L+R)/2;
						if (query(rt[r],rt[mid],0,n-1,0,now-1)+sm<=i)
						{
							pos=mid;
							L=mid+1;
						} else R=mid-1;
					}
					r=pos;
					break;
				}
			}
			ans++;
			now=r+1;
		}
		cout<<ans<<' ';
		Ans+=ans;
	}
	// cout<<Ans<<'\n';
	
		
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}