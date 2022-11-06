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

const int K=18;

#define oper __gcd
int st[K][1<<K];  // K such that 2^K>n
void st_init(vector<ll> a){
	fore(i,0,SZ(a))st[0][i]=a[i];
	fore(k,1,K)fore(i,0,SZ(a)-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

ll n;

pair<ll,ll> ex(ll pos){
	pair<ll,ll> res;
	ll g=st[0][pos];
	ll l=0,r=pos;
	while(l<=r){
		ll m=(l+r)/2;
		if(st_query(m,pos+1)==g)r=m-1;
		else l=m+1;
	}
	res.fst=l;
	l=pos,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st_query(pos,m+1)==g)l=m+1;
		else r=m-1;
	}
	res.snd=r;
	return res;
}

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
			if(lazy[k]!=-1){
				lazy[2*k]=lazy[k];
				lazy[2*k+1]=lazy[k];
			}
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			if(v!=-1)lazy[k]=v; // accumulate lazy
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

STree stl(200005),str(200005);

void print(ll n){
	cout<<"l: ";
	fore(i,0,n)cout<<stl.query(i,i+1)<<" ";
	cout<<"\n";
	cout<<"r: ";
	fore(i,0,n)cout<<str.query(i,i+1)<<" ";
	cout<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll p; cin>>n>>p;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		st_init(a);
		stl.upd(0,n,1);
		str.upd(0,n,1);
		vector<pair<ll,ll>> aa;
		fore(i,0,SZ(a))aa.pb({a[i],i});
		sort(ALL(aa));
		ll res=0;
		for(auto i:aa){
			if(i.fst>=p)break;
			//print(n);
			auto pa=ex(i.snd);
			//cout<<i.fst<<" "<<i.snd<<" "<<pa.fst<<" "<<pa.snd<<"\n";
			res+=str.query(pa.fst,i.snd)*i.fst;
			res+=stl.query(i.snd+1,pa.snd+1)*i.fst;
			stl.upd(pa.fst+1,pa.snd+1,0);
			str.upd(pa.fst,pa.snd,0);
		}
		//print(n);
		res+=(stl.query(0,n)-1)*p;
		cout<<res<<"\n";
	}
	
	return 0;
}