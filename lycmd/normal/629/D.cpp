#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010;
int n,r[N],h[N],p[N],v[N],f[N],tr[N];
vector<int>b;
void update(int x){
	tr[x]=max(tr[ls(x)],tr[rs(x)]);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r)
		return tr[x]=max(tr[x],k),void();
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql>qr)
		return 0;
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		res=max(res,query(ls(x),l,mid,ql,qr));
	if(qr>mid)
		res=max(res,query(rs(x),mid+1,r,ql,qr));
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i]>>h[i],b.push_back(v[i]=r[i]*r[i]*h[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++)
		p[i]=lower_bound(b.begin(),b.end(),v[i])-b.begin()+1;
	int m=b.size();
	for(int i=1;i<=n;i++)
		modify(1,1,m,p[i],f[i]=query(1,1,m,1,p[i]-1)+v[i]);
	cout<<fixed<<setprecision(8)<<acos(-1.0)*tr[1]<<"\n";
}