#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2333333;
int n,q,a[N],lt[N];
struct node{
	int l,r,len,lcnt,rcnt,lans,rans,ans;
	node(int x=0):
		l(x),r(x),len(1),lcnt(1),rcnt(1),lans(1),rans(1),ans(1){
	}
	node(int a,int b,int c,int d,int e,int f,int g,int h):
		l(a),r(b),len(c),lcnt(d),rcnt(e),lans(f),rans(g),ans(h){
	}
	node operator+(const node&rhs)const{
		int flg1=r<rhs.l,flg2=r>rhs.l;
		return{
			l,rhs.r,len+rhs.len,
			lcnt==len&&flg2?len+rhs.lcnt:lcnt,
			rhs.rcnt==rhs.len&&flg1?rcnt+rhs.len:rhs.rcnt,
			rcnt==len&&flg1?len+rhs.lans:
				lans==len&&flg2?len+rhs.lcnt:lans,
			rhs.lcnt==rhs.len&&flg2?rans+rhs.len:
				rhs.rans==rhs.len&&flg1?rcnt+rhs.len:rhs.rans,
			max(max(ans,rhs.ans),
				flg2?rans+rhs.lcnt:flg1?rcnt+rhs.lans:0)
		};
	}
};
node tr[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void add(int x,int k){
	tr[x].l+=k,tr[x].r+=k,lt[x]+=k;
}
void download(int x){
	int&t=lt[x];
	if(!t)return;
	add(ls(x),t),add(rs(x),t),t=0;
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
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		add(x,k);
		return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr,k);
	update(x); 
}
int query(){
	return tr[1].ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(cin>>q;q--;){
		int l,r,k;
		cin>>l>>r>>k;
		modify(1,1,n,l,r,k);
		cout<<query()<<"\n";
	}
}