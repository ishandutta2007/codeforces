// Lynkcat.
// Problem: C. Machine Learning
// Contest: Codeforces - 10.9(1)
// URL: https://codeforces.com/gym/403085/problem/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms

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
#define N 200005
using namespace std;
const int B=2100;
int n,m;
struct node
{
	int l,r,id;
}q[N],q1[N];
int cnt[N],tong[N];
int a[N],From[N];
int len,len1;
int ans[N];
inline void ins(int x)
{
	if (cnt[x])
	tong[cnt[x]]--;
	cnt[x]++;
	tong[cnt[x]]++;
}
inline void del(int x)
{
	if (cnt[x])
	tong[cnt[x]]--;
	cnt[x]--;
	tong[cnt[x]]++;
}
void BellaKira()
{
	poly g;
	cin>>n>>m;
	for (int i=1;i<=n;i++)	
		cin>>a[i],From[i]=(i-1)/B+1,g.push_back(a[i]);
	for (int i=1;i<=m;i++)
	{
		int opt;
		cin>>opt;
		if (opt==1)
		{
			++len;
			cin>>q[len].l>>q[len].r;
			q[len].id=i;
		} else
		{
			++len1;
			cin>>q1[len1].l>>q1[len1].r;
			q1[len1].id=i;
			g.push_back(q1[len1].r);
		}
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	for (int i=1;i<=n;i++) a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+1;
	for (int i=1;i<=len1;i++) q1[i].r=lower_bound(g.begin(),g.end(),q1[i].r)-g.begin()+1;
	sort(q+1,q+len+1,[&](node x,node y)
	{
		if (From[x.l]!=From[y.l]) return From[x.l]<From[y.l];
		if (From[x.r]!=From[y.r]) return From[x.r]<From[y.r];
		return x.id<y.id;
	});
	int l=1,r=0,tim=0;
	for (int i=1;i<=len;i++)
	{
		while (tim<len1&&q1[tim+1].id<q[i].id)
		{
			++tim;
			int x=q1[tim].l;
			int &y=q1[tim].r;
			if (q1[tim].l>=l&&q1[tim].l<=r)
			{
				del(a[x]);
				swap(a[x],y);
				ins(a[x]);
			} else
			{
				swap(a[x],y);
			}
		}
		while (tim&&q1[tim].id>q[i].id)
		{
			int x=q1[tim].l;
			int &y=q1[tim].r;
			if (q1[tim].l>=l&&q1[tim].l<=r)
			{
				del(a[x]);
				swap(a[x],y);
				ins(a[x]);
			} else
			{
				swap(a[x],y);
			}
			tim--;
		}
		while (l>q[i].l)
		{
			--l;
			ins(a[l]);
		}
		while (r<q[i].r)
		{
			++r;
			ins(a[r]);
		}
		while (l<q[i].l)
		{
			del(a[l]);
			l++;
		}
		while (r>q[i].r)
		{
			del(a[r]);
			r--;
		}
		// cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].id<<endl;
		int nw=0;
		for (int j=1;j;j++)
			if (!tong[j])
			{
				nw=j;
				break;
			}
		ans[q[i].id]=nw;
	}
	for (int i=1;i<=m;i++)
		if (ans[i]) cout<<ans[i]<<'\n';
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