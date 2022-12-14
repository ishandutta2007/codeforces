#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int ios = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
const int N = 5e5+10,inf = 1e18;
int a[N];
using pii = pair<int,int>;
struct nd{
	int l,r,id;
}q[N];
int ans[N],pos[N];
struct node{
	int l,r;
	pii mi;
}tr[N*4];
void pushup(int u) { tr[u].mi = min(tr[u<<1].mi,tr[u<<1|1].mi); }
void build(int u,int l,int r)
{
	tr[u] = {l,r};
	int mid = l + r >>1;
	if(l==r) return;
	build(u<<1,l,mid); build(u<<1|1,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int prepos,int nowpos)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
	    tr[u].mi.first = prepos, tr[u].mi.second = nowpos;
		return;
	}
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) update(u<<1,l,r,prepos,nowpos);
	else update(u<<1|1,l,r,prepos,nowpos);
	pushup(u);
}
pii query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mi;
	pii ans = {1e18,0};
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid) ans = min(ans,query(u<<1,l,r));
	if(r>mid) ans = min(ans,query(u<<1|1,l,r));
	return ans;
}
void solve()
{
	int n; cin>>n;
	build(1,1,n);
	for(int i=1;i<=n;i++) cin>>a[i];
	int k; cin>>k;
	for(int i=1;i<=k;i++) cin>>q[i].l>>q[i].r,q[i].id = i;
	sort(q+1,q+k+1,[](nd a,nd b) { return a.r < b.r;} ) ;
	for(int i=1,j=1;i<=k;i++)
	{
		for(;j<=q[i].r&&j<=n;j++)
		{
			if(pos[a[j]]) update(1,pos[a[j]],pos[a[j]],inf,pos[a[j]]);
			update(1,j,j,pos[a[j]],j);
			pos[a[j]] = j;
		}
		pii res = query(1,q[i].l,q[i].r);
		if(res.first < q[i].l) ans[q[i].id] = a[res.second];
	}
		
	for(int i=1;i<=k;i++) cout<<ans[i]<<endl;
}

signed main()
{
	int tt=1;
//	cin>>tt;
	while(tt--)
	{
		solve();
	}
}