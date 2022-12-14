// Lynkcat.
// Problem: B. Lucky Queries
// Contest: Codeforces - 10.9
// URL: https://codeforces.com/gym/403061/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
#define N 1000005
using namespace std;
string st;
int n,m;
struct node
{
	int rt4[2];
	int rt7[2];
	int lf4[2];
	int lf7[2];
	int ans[2];
	node()
	{
		for (int i=0;i<2;i++)
			rt4[i]=rt7[i]=lf4[i]=lf7[i]=ans[i]=0;
	}
};
bool tag[N<<2];
node tr[N<<2];
inline void flip(int k)
{
	swap(tr[k].rt4[0],tr[k].rt4[1]);
	swap(tr[k].rt7[0],tr[k].rt7[1]);
	swap(tr[k].lf4[0],tr[k].lf4[1]);
	swap(tr[k].lf7[0],tr[k].lf7[1]);
	swap(tr[k].ans[0],tr[k].ans[1]);
	tag[k]^=1;
}
inline void pushdown(int k)
{
	if (!tag[k]) return;
	flip(k<<1);
	flip(k<<1|1);
	tag[k]=0;
}
inline node merge(node &x,node &y)
{
	node res;
	for (int i=0;i<2;i++)
	{
		res.ans[i]=
		max({x.ans[i],y.ans[i],
		x.rt4[i]+max(y.lf7[i],y.lf4[i]),
		x.rt7[i]+y.lf7[i]});
		
		res.rt4[i]=x.rt4[i]+y.rt4[i];
		res.rt7[i]=max(x.rt4[i]+y.rt7[i],x.rt7[i]+y.lf7[i]);
		
		res.lf4[i]=max(x.rt4[i]+y.lf4[i],
		x.lf4[i]+y.lf7[i]);
		
		res.lf7[i]=x.lf7[i]+y.lf7[i];
	}
	return res;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		if (st[l-1]=='4')
		{
			tr[k].rt4[0]=1;
			tr[k].lf4[0]=1;
			tr[k].rt7[1]=1;
			tr[k].lf7[1]=1;
		}
		else
		{
			tr[k].rt4[1]=1;
			tr[k].lf4[1]=1;
			tr[k].rt7[0]=1;
			tr[k].lf7[0]=1;
		}
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
	// cout<<k<<" "<<l<<" "<<r<<" "<<tr[k].ans[0]<<" "<<tr[k].lf7[0]<<" "<<tr[k].rt7[0]<<endl;
}
void update(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		flip(k);
		return;
	}
	int mid=l+(r-l)/2;
	int x=tr[k<<1|1].lf7[0];
	pushdown(k);
	if (L<=mid) update(k<<1,l,mid,L,R);
	if (R>mid) update(k<<1|1,mid+1,r,L,R);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
	// cout<<k<<" "<<l<<" "<<r<<" "<<tr[k].ans[0]<<endl;
}
void BellaKira()
{
	cin>>n>>m;
	cin>>st;
	build(1,1,n);
	while (m--)
	{
		string st;
		cin>>st;
		if (st=="count")
		{
			cout<<tr[1].ans[0]<<'\n';
		} else
		{
			int l,r;
			cin>>l>>r;
			update(1,1,n,l,r);
		}
	}
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