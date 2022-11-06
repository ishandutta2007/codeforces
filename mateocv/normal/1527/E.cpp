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

ll INF=(1ll<<60);

/*----------------------STLAZYLL-------------------------*/
struct STree { // example: range sum with range addition
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	STree(): st(0,0), lazy(0,0), n(0) {}
	void push(ll k, ll s, ll e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return INF; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

vector<STree> st(2);

const int MAXN=35005;

ll ne[MAXN],la[MAXN];

void print(ll n){
	fore(i,0,2){
		fore(j,0,n+1){
			ll pr=st[i].query(j,j+1);
			if(pr==INF)cout<<"INF ";
			else cout<<pr<<" ";
		}
		cout<<"\n";
	}
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	mset(la,-1);
	for(ll i=n-1;i>=0;i--){
		if(la[a[i]]==-1){
			ne[i]=-1;
		}else{
			ne[i]=la[a[i]];
		}
		la[a[i]]=i;
	}
	fore(k,0,2)st[k]=STree(MAXN);
	st[0].upd(0,n,INF);
	st[1].upd(n,n+1,INF);
	//fore(i,0,n)cout<<ne[i]<<" ";
	//cout<<"\n";
	//print(n);
	fore(j,0,k){
		//cout<<j<<":\n";
		//print(n);
		for(ll i=n-1;i>=0;i--){
			//cout<<i<<":\n";
			ll ni=ne[i];
			if(ni!=-1){
				st[0].upd(ni+1,n+1,ni-i);
			}
			//print(n,k);
			st[1].upd(i,i+1,st[0].query(i+1,n+1));
			//print(n);
		}
		//print(n);
		//fore(i,0,n+1)st[0].upd(i,i+1,st[1].query(i,i+1)-st[0].query(i,i+1));
		//fore(i,0,n+1)st[1].upd(i,i+1,-st[1].query(i,i+1));
		//st[1].upd(n,n+1,INF);
		swap(st[0],st[1]);
		st[1]=STree(MAXN);
		st[1].upd(n,n+1,INF);
		//print(n);
	}
	cout<<st[0].query(0,1)<<"\n";
	return 0;
}