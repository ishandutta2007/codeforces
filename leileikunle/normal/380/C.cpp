#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
string s;
#define endl '\n'
int ios = [](){ ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); return 0; }();
namespace segmentree
{
	const int N = 1e6+10;
	struct node{
		int l,r;
		int sum,ll,rr; 
	}tr[N*4];
	void eval(node &ro,node &l,node &r)
	{
		int t = min(l.ll,r.rr);
		ro.sum = l.sum+r.sum+t;
		ro.ll = l.ll+r.ll-t;
		ro.rr = l.rr+r.rr-t;
	}
	void pushup(int u)
	{
		eval(tr[u],tr[u<<1],tr[u<<1|1]);
	}
	void build(int u,int l,int r)
	{
		tr[u] = {l,r};
		if(l==r)
		{
			tr[u]= {l,r,0,s[l-1]=='(',s[l-1]==')'};
		}else{
			int mid = l + r >>1;
			build(u<<1,l,mid); 
			build(u<<1|1,mid+1,r);
			pushup(u);
		}
	}
	node query(int u,int l,int r)
	{
		if(tr[u].l>=l&&tr[u].r<=r) return tr[u];
		else{
			int mid = tr[u].l + tr[u].r >>1;
			if(r<=mid) return query(u<<1,l,r);
			else if(l>mid) return query(u<<1|1,l,r);
			else
			{
				node res;
				node L = query(u<<1,l,r);
				node R = query(u<<1|1,l,r);
				eval(res,L,R);
				return res;
			}
		}
	}
}

int main()
{
	cin>>s;
	int t = s.size();
	int q; cin>>q;
	segmentree::build(1,1,t);
	while(q--)
	{
		int l,r; cin>>l>>r;
		cout<<segmentree::query(1,l,r).sum * 2 <<endl;
	}
}