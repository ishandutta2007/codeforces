#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=-1;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(lazy[k]==-1)return; // if neutral, nothing to do
		st[k]=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

const int MAXN=200105;

STree st(MAXN);

void print(){
	//return;
	fore(i,0,20)cout<<st.query(i,i+1)<<" ";
	cout<<"\n";
}

void add(ll x){
	auto s=st.query(0,x);
	ll pos=1,l=0,r=MAXN,sp=0;
	st.push(pos,l,r);
	while(r-l>1){
		ll m=(l+r)/2;
		st.push(2*pos,l,m);
		st.push(2*pos+1,m,r);
		if(m<x||sp+st.st[2*pos]==s+m-x){
			sp+=st.st[2*pos];
			pos=2*pos+1;
			l=m;
		}else{
			pos=2*pos;
			r=m;
		}
	}
	//cout<<"add "<<x<<" "<<l<<" "<<r<<"\n";
	st.upd(x,l,0);
	st.upd(l,l+1,1);
	//print();
}

void rem(ll x){
	auto s=st.query(0,x);
	ll pos=1,l=0,r=MAXN,sp=0;
	st.push(pos,l,r);
	while(r-l>1){
		ll m=(l+r)/2;
		st.push(2*pos,l,m);
		st.push(2*pos+1,m,r);
		if(m<x||sp+st.st[2*pos]==s){
			sp+=st.st[2*pos];
			pos=2*pos+1;
			l=m;
		}else{
			pos=2*pos;
			r=m;
		}
	}
	//cout<<"rem "<<x<<" "<<l<<" "<<r<<"\n";
	st.upd(x,l,1);
	st.upd(l,l+1,0);
	//print();
}

ll get(){
	ll pos=1,l=0,r=MAXN;
	while(r-l>1){
		ll m=(l+r)/2;
		st.push(2*pos,l,m);
		st.push(2*pos+1,m,r);
		if(st.st[2*pos+1]==0){
			pos=2*pos;
			r=m;
		}else{
			pos=2*pos+1;
			l=m;
		}
	}
	return l;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)add(a[i]);
	//print();
	while(q--){
		ll pos,val; cin>>pos>>val; pos--;
		rem(a[pos]);
		//print();
		a[pos]=val;
		add(a[pos]);
		//print();
		cout<<get()<<"\n";
	}
	
	return 0;
}