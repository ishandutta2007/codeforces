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

ll INF=2e9;

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return INF; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

STree st(2000006);

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<pair<ll,pair<ll,ll>>> v(n);
	fore(i,0,n){
		cin>>v[i].snd.fst>>v[i].snd.snd>>v[i].fst;
		v[i].snd.fst=2*(v[i].snd.fst-1);
		v[i].snd.snd=2*(v[i].snd.snd-1)+1;
	}
	m=2*(m-1)+1;
	ll res=1e18;
	sort(ALL(v));
	ll l=0,r=0;
	while(1){
		//cout<<l<<" "<<r<<"\n";
		auto q=st.query(0,m);
		//cout<<q<<endl;
		if(q){
			res=min(res,v[r-1].fst-v[l].fst);
			st.upd(v[l].snd.fst,v[l].snd.snd,-1);
			l++;
		}else{
			if(r==SZ(v))break;
			st.upd(v[r].snd.fst,v[r].snd.snd,1);
			r++;
		}
	}
	cout<<res<<"\n";
	
	return 0;
}