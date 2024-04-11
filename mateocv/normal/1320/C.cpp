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

/*----------------------STL-------------------------*/
struct STree { // example: range sum with range addition
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
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
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return -9e18; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main(){FIN;
	ll n,m,p; cin>>n>>m>>p;
	pair<ll,ll> a[n],b[m];
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].snd*=-1;
	fore(i,0,m)cin>>b[i].fst>>b[i].snd,b[i].snd*=-1;
	sort(a,a+n);
	sort(b,b+m);
	vector<pair<ll,ll>> v[2];
	fore(i,0,n){
		while(SZ(v[0])&&v[0].back().snd<=a[i].snd)v[0].pop_back();
		v[0].pb(a[i]);
	}
	fore(i,0,m){
		while(SZ(v[1])&&v[1].back().snd<=b[i].snd)v[1].pop_back();
		v[1].pb(b[i]);
	}
	fore(k,0,2){
		//cout<<k<<" : \n";
		for(auto &i:v[k]){
			i.snd*=-1;
			//cout<<i.fst<<" "<<i.snd<<"\n";
		}
	}
	STree st(1000006);
	pair<pair<ll,ll>,ll> z[p];
	fore(i,0,p)cin>>z[i].fst.fst>>z[i].fst.snd>>z[i].snd;
	sort(z,z+p);
	/*ll va=v[0].fst,vap=1,g=-v[0].snd,s=0;
	ll gx[1000006];
	fore(i,0,n)gx=NEUT;
	fore(i,0,p){
		ll br=0;
		while(z[i].fst.fst>=va){
			if(vap==SZ(v[0])){br++; break;}
			va=v[vap].fst,g=-v[vap].snd;
			vap++; s+=z[i].snd;
		}
		if(br)break;
		gx[z[i].fst.fst]=s-g;
	}
	ll res=-v[0].snd-v[1].snd;
	fore(i,0,m){
		
	}*/
	fore(i,0,SZ(v[1])){
		if(i==0)st.upd(0,1000006,-v[1][0].snd);
		else{
			st.upd(v[1][i-1].fst,1000006,-v[1][i].snd+v[1][i-1].snd);
		}
		if(i==SZ(v[1])-1)st.upd(v[1][i].fst,10000006,-9e18+v[1][i].snd);
	}
	//fore(i,0,13)cout<<st.query(i,i+1)<<" "; cout<<"\n";
	ll ult=0;
	ll res=-9e18;
	fore(i,0,SZ(v[0])){
		//vector<ll> ag;
		fore(j,ult,p){
			if(z[j].fst.fst<v[0][i].fst)st.upd(z[j].fst.snd,1000006,z[j].snd),ult++;//,cout<<z[j].fst.snd+1<<" "<<z[j].snd<<"\n";
			else break;
		}
	//	fore(i,0,13)cout<<st.query(i,i+1)<<" "; cout<<"\n";
		res=max(res,st.query(0,1000006)-v[0][i].snd);
	}
	cout<<res;
	return 0;
}