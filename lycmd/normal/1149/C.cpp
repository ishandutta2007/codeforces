#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=800010;
int n,m;
struct node{
	int s,lmx,rmn,lans,rans,mans,ans;
	node(char k=0){
		s=k==40?1:-1;
		lmx=max(s,0),rmn=min(s,0);
		lans=rans=mans=ans=1;
	}
	node(int a,int b,int c,int d,int e,int f,int g):
		s(a),lmx(b),rmn(c),lans(d),rans(e),mans(f),ans(g){
		}
	node operator+(const node&rhs)const{
		return{
			s+rhs.s,
			max(lmx,s+rhs.lmx),
			min(rhs.rmn,rhs.s+rmn),
			max(max(lans,rhs.lans-s),mans+rhs.lmx),
			max(max(rhs.rans,rans+rhs.s),rhs.mans-rmn),
			max(mans+rhs.s,rhs.mans-s),
			max(max(ans,rhs.ans),max(rhs.lans-rmn,rans+rhs.lmx))
		};
	}
};
node tr[N];
string s;
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=node(s[l]);
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
	if(p<=mid)modify(ls(x),l,mid,p,k);
	else modify(rs(x),mid+1,r,p,k);
	update(x);
}
int query(){
	return tr[1].ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s,n=s.size(),s=" "+s;
	build(1,1,n);
	cout<<query()<<"\n";
	while(m--){
		int x,y;
		cin>>x>>y;
		swap(s[x],s[y]);
		modify(1,1,n,x,s[x]);
		modify(1,1,n,y,s[y]);
		cout<<query()<<"\n";
	}
}