#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
const LL L=2e9;

struct I{
	int cnt;
	LL sum,spf;
	I(){
		cnt=sum=spf=0;
	}
	I(int _c,LL _s,LL _p){
		cnt=_c,sum=_s,spf=_p;
	}
};
inline I operator+(const I l,const I r){
#define pp(a,b) a.b
	return (I){
		pp(l,cnt)+pp(r,cnt),
		pp(l,sum)+pp(r,sum),
		pp(l,spf)+pp(l,cnt)*pp(r,sum)+pp(r,spf)
	};
}
struct Node{
	Node *l,*r;
	I in;
	Node(){
		l=r=NULL;
	}
	inline void upd(){
#define pi(p) ((p)?(p)->in:I())
		in=pi(l)+pi(r);
	}
};
typedef Node *np;

struct SegTree{
	np root;
	SegTree(){root=NULL;}
	void _add(LL pos,LL ll,LL rr,np &root,int val){
		if(!root)root=new Node();
		if(ll==rr){
			if(val==1)root->in=(I){1,(LL)pos,(LL)pos};
			else root->in=I();
			return;
		}
		LL mid=(ll+rr)>>1;
		if(pos<=mid){
			_add(pos,ll,mid,root->l,val);
		}else{
			_add(pos,mid+1,rr,root->r,val);
		}
		root->upd();
	}
	void add(LL pos,int val){
		_add(pos,-L,L,root,val);
	}
	I _qe(LL l,LL r,LL ll,LL rr,np root){
		if(!root||r<ll||rr<l)return I();
		if(l<=ll&&rr<=r)return root->in;
		LL mid=(ll+rr)>>1;
		return _qe(l,r,ll,mid,root->l)
			+_qe(l,r,mid+1,rr,root->r);
	}
	LL qe(LL l,LL r){
		I res=_qe(l,r,-L,L,root);
		return 2*res.spf-res.sum*res.cnt-res.sum;
	}
}tr;

int x[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		tr.add(x[i],1);
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int p,d;
			scanf("%d%d",&p,&d);
			tr.add(x[p],-1);
			tr.add(x[p]+=d,1);
		}else if(op==2){
			int l,r;
			scanf("%d%d",&l,&r);
			cout<<tr.qe(l,r)<<endl;
		}else cerr<<"qwq?"<<endl;
	}
	return 0;    
}