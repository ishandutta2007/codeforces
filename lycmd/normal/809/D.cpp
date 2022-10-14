#include<bits/stdc++.h>
using namespace std;
int n;
mt19937 rnd(chrono::steady_clock::
	now().time_since_epoch().count());
auto gen=[](int l,int r){return rnd()%(r-l+1)+l;};
struct fhq_treap{
	static int const N=500010;
	int rt=0,tot,sz[N],tr[N],val[N],ls[N],rs[N],lt[N];
	void update(int x){
		sz[x]=sz[ls[x]]+sz[rs[x]]+1;
	}
	void add(int x,int k){
		if(x&&k)lt[x]+=k,tr[x]+=k;
	}
	void download(int x){
		if(!x||!lt[x])return;
		add(ls[x],lt[x]),add(rs[x],lt[x]),lt[x]=0;
	}
	int newnode(int k){
		return sz[++tot]=1,tr[tot]=k,val[+tot]=gen(1,N),tot;
	}
	int merge(int x,int y){
		if(!x||!y)
			return x+y;
		download(x);
		download(y);
		return val[x]<val[y]?
			(rs[x]=merge(rs[x],y),update(x),x):
			(ls[y]=merge(x,ls[y]),update(y),y);
	}
	void split(int cur,int k,int&x,int&y){
		if(!cur){
			x=y=0;return;
		}
		download(cur);
		if(tr[cur]<=k)
			x=cur,split(rs[cur],k,rs[cur],y);
		else
			y=cur,split(ls[cur],k,x,ls[cur]);
		update(cur);
	}
	int findkth(int x,int k){
		download(x);
		return k==sz[ls[x]]+1?x:k<=sz[ls[x]]?findkth(ls[x],k):
			findkth(rs[x],k-sz[ls[x]]-1);
	}
	void insert(int k){
		int x,y;
		split(rt,k,x,y);
		rt=merge(merge(x,newnode(k)),y);
	}
	void erase(int k){
		int x,y,z;
		split(rt,k,x,z);
		split(x,k-1,x,y);
		rt=merge(merge(x,merge(ls[y],rs[y])),z);
	}
	int getpre(int k){
		int x,y;
		split(rt,k-1,x,y);
		int ans=tr[findkth(x,sz[x])];
		rt=merge(x,y);
		return ans;
	}
	int getnxt(int k){
		int x,y;
		split(rt,k,x,y);
		int ans=tr[findkth(y,1)];
		rt=merge(x,y);
		return ans;
	}
	void modify(int l,int r){
		int a,b,c,d;
		split(rt,r,a,b);
		split(a,l-1,c,d);
		add(d,1);
		rt=merge(merge(c,d),b);
	}
};
fhq_treap tr;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		if(i>1){
			int p=tr.getnxt(r-1);
			tr.modify(l,r-1);
			if(p)tr.erase(p);
		}
		tr.insert(l);
	}
	cout<<tr.sz[tr.rt]<<"\n";
}