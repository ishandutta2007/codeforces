#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=12,M=400010;
int n,m,q,ord[N<<2];
array<int,N>a[M];
struct dsu{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;i++)f[i]=i;
	}
	int find(int x){
		return x^f[x]?f[x]=find(f[x]):x;
	}
	int merge(int x,int y){
		int fx=find(x),fy=find(y);
		return fx^fy?(f[fx]=fy,1):0;
	}
}s;
struct node{
	int cnt;
	array<int,N>uc,dc,uf,df;
	node(int a=0):cnt(a){}
	node(array<int,N>&a){
		cnt=n,s.init(n),uc=dc=a;
		for(int i=1;i<n;i++)
			cnt-=uc[i]==uc[i+1]&&s.merge(i,i+1);
		for(int i=1;i<=n;i++)
			uf[i]=df[i]=s.find(i);
	}
	node operator+(const node&rhs)const{
		node res(cnt+rhs.cnt);
		res.uc=uc,res.dc=rhs.dc;
		s.init(4*n);
		for(int i=1;i<=n;i++)
			s.merge(i,uf[i]),s.merge(i+n,df[i]),
			s.merge(i+2*n,rhs.uf[i]+2*n),
			s.merge(i+3*n,rhs.df[i]+2*n);
		for(int i=1;i<=n;i++)
			res.cnt-=dc[i]==rhs.uc[i]&&s.merge(i+n,i+2*n);
		memset(ord,0,sizeof ord);
		for(int i=1;i<=n;i++){
			if(!ord[s.find(i)])
				ord[s.find(i)]=i;
			res.uf[i]=ord[s.find(i)];
		}
		for(int i=3*n+1;i<=4*n;i++){
			if(!ord[s.find(i)])
				ord[s.find(i)]=i-2*n;
			res.df[i-3*n]=ord[s.find(i)];
		}
		return res;
	}
};
node tr[M];
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
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[j][i];
	build(1,1,m);
	while(q--){
		int l,r;cin>>l>>r;
		cout<<query(1,1,m,l,r).cnt<<"\n";
	}
}