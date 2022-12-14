#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ios = [](){ ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); return 0; }();
const int N = 5e5+10;
int a[N];
int cnt,t;
struct node{
	int l,r;
	int g;
}tr[N*4];
void pushup(int u)
{
	tr[u].g = __gcd(tr[u<<1].g,tr[u<<1|1].g);
}
void build(int u,int l,int r)
{
	tr[u] = {l,r};
	if(l==r) tr[u].g = a[l];
	else{
		int mid = l + r >>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}
void update(int u,int l,int r,int k)
{
	if(tr[u].l>=l&&tr[u].r<=r) tr[u].g = k;
	else
	{
		int mid = tr[u].l + tr[u].r >>1;
		if(l<=mid) update(u<<1,l,r,k);
		if(r>mid) update(u<<1|1,l,r,k);
		pushup(u);
	}
} 
void query(int u,int l,int r)
{
	if(cnt==2) return;
	if(tr[u].l==tr[u].r)
	{
		if(tr[u].g % t) cnt++;
		return;
	}
	int mid = tr[u].l + tr[u].r >>1;
	if(l<=mid  && tr[u<<1].g % t) query(u<<1,l,r);
	if(r>mid && tr[u<<1|1].g % t) query(u<<1|1,l,r);
}
//int query1(int u,int l,int r)
//{
//	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].g;
//	else
//	{
//		int q=0,w=0;
//		int mid = tr[u].l + tr[u].r >>1;
//		if(l<=mid) q = query1(u<<1,l,r);
//		if(r>mid) w =query1(u<<1|1,l,r);
//		if(!q&&!w) return __gcd(q,w);
//		else if(!q&&w) return w;
//		else return q;
//	}
//}
int main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	int q; cin>>q;
	while(q--)
	{
		cnt = 0;
		int x; cin>>x;
		if(x==1)
		{
			int l,r; cin>>l>>r>>t;
			query(1,l,r);
//			cout<<cnt<<" ";
			if(cnt<=1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
//			cout<<query1(1,1,n)<<endl;
		}else{
			int l,r; cin>>l>>r;
			update(1,l,l,r);
//			cout<<query1(1,1,n)<<endl;
		}
	}
}