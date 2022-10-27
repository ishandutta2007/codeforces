// LUOGU_RID: 90662338
#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,q,c[26][N],cur[26];
string s,t;
struct segtree{
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define mid (((l)+(r))>>1)
	static int const T=N<<2;
	int tr[T],lt[T];
	segtree(){
		memset(tr,0,sizeof tr);
		memset(lt,-1,sizeof lt);
	}
	void update(int x){
		tr[x]=tr[ls(x)]+tr[rs(x)];
	}
	void cov(int x,int l,int r,int k){
		if(~k)lt[x]=k,tr[x]=(r-l+1)*k;
	}
	void download(int x,int l,int r){
		int&t=lt[x];
		if(~t)cov(ls(x),l,mid,t),cov(rs(x),mid+1,r,t),t=-1;
	}
	void build(int x,int l,int r,int*a){
		if(l==r)
			return tr[x]=a[l],void();
		build(ls(x),l,mid,a);
		build(rs(x),mid+1,r,a);
		update(x);
	}
	void cover(int x,int l,int r,int ql,int qr,int k){
		if(ql>qr)
			return;
		if(ql<=l&&r<=qr)
			return cov(x,l,r,k);
		download(x,l,r);
		if(ql<=mid)
			cover(ls(x),l,mid,ql,qr,k);
		if(qr>mid)
			cover(rs(x),mid+1,r,ql,qr,k);
		update(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)
			return tr[x];
		download(x,l,r);
		int res=0;
		if(ql<=mid)
			res+=query(ls(x),l,mid,ql,qr);
		if(qr>mid)
			res+=query(rs(x),mid+1,r,ql,qr);
		return res;
	}
	void print(int x,int l,int r,char c,string&t){
		if(l==r)
			return void(tr[x]&&(t[l]=c));
		download(x,l,r);
		print(ls(x),l,mid,c,t);
		print(rs(x),mid+1,r,c,t);
	}
#undef ls
#undef rs
};
segtree tr[26];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q>>s,s=" "+s,t.resize(n+1);
	for(int i=1;i<=n;i++)
		c[s[i]-97][i]++;
	for(int i=0;i<26;i++)
		tr[i].build(1,1,n,c[i]);
	for(int l,r;q--;){
		cin>>l>>r;
		int c=0,p=-1;
		for(int i=0;i<26;i++)
			if((cur[i]=tr[i].query(1,1,n,l,r))&1)
				c++,p=i;
		if(c>1||c!=(r-l+1)%2)
			continue;
		for(int i=0;i<26;i++)
			tr[i].cover(1,1,n,l,r,0);
		if(~p)cur[p]--,tr[p].cover(1,1,n,(l+r)/2,(l+r)/2,1);
		for(int i=0,j=0;i<26;j+=cur[i++]/2)
			tr[i].cover(1,1,n,l+j,l+j+cur[i]/2-1,1),
			tr[i].cover(1,1,n,r-j-cur[i]/2+1,r-j,1);
	}
	for(int i=0;i<26;i++)
		tr[i].print(1,1,n,i+97,t);
	cout<<t.substr(1)<<"\n";
}