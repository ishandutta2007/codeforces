#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
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
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,c; cin>>n>>c;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		//sort(ALL(a));
		set<ll> st;
		for(auto i:a)st.insert(i);
		STree str(c+1);
		vector<ll> no;
		if(!st.count(1)){
			cout<<"No\n";
			continue;
		}
		ll br=0;
		fore(i,2,c+1){
			if(!st.count(i))no.pb(i);
		}
		fore(i,2,c+1){
			if(st.count(i)){
				if(str.query(i,i+1)){
					br++;
					break;
				}else{
					for(auto j:no){
						if(i*j>c)break;
						str.upd(i*j,min(i*(j+1),c+1),1);
					}
				}
			}
		}
		if(br)cout<<"No\n";
		else cout<<"Yes\n";
	}
	
	return 0;
}