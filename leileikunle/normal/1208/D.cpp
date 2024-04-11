#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ios = [](){ ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); return 0; }();
const int N = 2e5+10;
#define int long long
struct node{
	int l,r;
	int tag,mi;
}tr[N*4];
int a[N];
void pushup(int u)
{
	tr[u].mi = min(tr[u<<1].mi,tr[u<<1|1].mi);
}
void pushdown(int u)
{
	node &ro = tr[u],&l = tr[u<<1],&r = tr[u<<1|1];
	if(ro.tag)
	{
		l.mi+=ro.tag; l.tag+=ro.tag;
		r.mi+=ro.tag; r.tag+=ro.tag;
		ro.tag=0;
	}
}
void build(int u,int l,int r)
{
	tr[u] = {l,r};
	if(l==r)
	{
		tr[u].mi = a[l];
		return;
	}
	int mid = l + r >>1;
	build(u<<1,l,mid); build(u<<1|1,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int k)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].mi+=k; 
		tr[u].tag +=k;
	}else{
		pushdown(u);
		int mid = tr[u].l + tr[u].r >>1;
		if(l<=mid) update(u<<1,l,r,k);
		if(r>mid) update(u<<1|1,l,r,k);
		pushup(u);
	}
}

int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mi;
	else{
		pushdown(u);
		int ans = 0x3f3f3f3f;
		int mid = tr[u].l + tr[u].r >>1;
		if(l<=mid) ans = query(u<<1,l,r);
		if(r>mid) ans = min(ans,query(u<<1|1,l,r));
		return ans;
	}
}
int cnt;
int ans[N];
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=n;
		while(l<r)
		{
			int mid = l + r +1 >>1;
			if(query(1,mid,n)>0) r = mid - 1;
			else l=mid;
		}
		ans[l] = ++cnt;
		
		update(1,l,l,1e12);
		update(1,l,n,-cnt);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" "; 
}