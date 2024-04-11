#include<bits/stdc++.h>
using namespace std;
int const N=1000010,M=30000010;
int n,m,x=-1,a,b,c,d,tot,sz[M],ls[M],rs[M],rt[N],p[N],q[N],w[N],tr[N];
int f(int z){
	return(z+x)%n+1;
}
void modify(int&x,int y,int l,int r,int p){
	x=++tot,ls[x]=ls[y],rs[x]=rs[y],sz[x]=sz[y]+1;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls[x],ls[y],l,mid,p);
	else
		modify(rs[x],rs[y],mid+1,r,p);
}
int query(int x,int l,int r,int ql,int qr){
	if(!x)
		return 0;
	if(ql<=l&&r<=qr)
		return sz[x];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		res+=query(ls[x],l,mid,ql,qr);
	if(qr>mid)
		res+=query(rs[x],mid+1,r,ql,qr);
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>q[i],w[q[i]]=i;
	for(int i=1;i<=n;i++)
		modify(rt[i],rt[i-1],1,n,w[p[i]]);
	for(cin>>m;m--;){
		cin>>a>>b>>c>>d;
		int l1=min(f(a),f(b)),r1=max(f(a),f(b)),
			l2=min(f(c),f(d)),r2=max(f(c),f(d));
		cout<<(x=query(rt[r1],1,n,l2,r2)-query(rt[l1-1],1,n,l2,r2))<<"\n";
	}
}