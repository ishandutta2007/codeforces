#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010;
int n,q,val,a[N];
struct node{
	int ans;
	vector<pair<int,int> >l,r;
	node(int k=0):ans(k>=val){
		l.push_back({k,1});
		r.push_back({k,1});
	}
	node operator+(const node&rhs)const{
		node res;
		res.ans=ans+rhs.ans;
		res.l=l,res.r=rhs.r;
		for(auto i:r)
			for(auto j:rhs.l)
				if((i.first|j.first)>=val)
					res.ans+=i.second*j.second;
		int t=res.l.back().first;
		for(auto i:rhs.l)
			if(t<(t|i.first))
				res.l.push_back({t|=i.first,i.second});
			else
				res.l.back().second+=i.second;
		t=res.r.back().first;
		for(auto i:r)
			if(t<(t|i.first))
				res.r.push_back({t|=i.first,i.second});
			else
				res.r.back().second+=i.second;
		return res;
	}
};
node tr[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=node(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=node(k);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x);
}
node query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1;
	if(qr<=mid)
		return query(ls(x),l,mid,ql,qr);
	if(ql>mid)
		return query(rs(x),mid+1,r,ql,qr);
	return query(ls(x),l,mid,ql,qr)+query(rs(x),mid+1,r,ql,qr); 
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q>>val;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--){
		int op,x,y;cin>>op>>x>>y;
		if(op<2)
			modify(1,1,n,x,y);
		else
			cout<<query(1,1,n,x,y).ans<<"\n";
	}
}