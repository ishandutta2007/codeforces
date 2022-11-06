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

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper(a,b) a+b
const ll NEUT=0;
struct STree { // [cerrado-abierto)
    vector<ll> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]+=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    ll query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

STree cant(200005),cantl(200005),val(200005);

ll sum=0,cl=0;
map<ll,ll> mp;
vector<ll> ump;
ll solve(){
	if(cl==0)return sum;
	ll l=0,r=200005;
	while(l<=r){
		ll m=(l+r)/2;
		if(cant.query(m,200005)>=cl)l=m+1;
		else r=m-1;
	}
	ll res=sum;
	if(cantl.query(r,200005)<cant.query(r,200005)){
		res+=val.query(r,200005);
	}else{
		if(cl==cant.query(0,200005)){
			res+=val.query(r,200005);
			res-=val.query(r,l);
		}else{
			res+=val.query(r,200005);
			res-=val.query(r,l);
			ll el=0,er=200005;
			while(el<=er){
				ll m=(el+er)/2;
				if(cant.query(m,200005)>=cl+1)el=m+1;
				else er=m-1;
			}
			res+=val.query(er,el);
		}
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> v;
	fore(i,0,n){
		ll a,b; cin>>a>>b;
		v.pb({a,b});
	}
	set<ll> s;
	s.insert(0);
	fore(i,0,n)s.insert(abs(v[i].snd));
	for(auto i:s)ump.pb(i);
	fore(i,0,SZ(ump))mp[ump[i]]=i;
	fore(i,0,n){
		if(v[i].snd>0)v[i].snd=mp[v[i].snd];
		else v[i].snd=-mp[-v[i].snd];
	}
//	for(auto i:mp)cout<<i.fst<<" "<<i.snd<<"\n";
//	for(auto i:ump)cout<<i<<" "; cout<<"\n";
	fore(i,0,n){
		if(v[i].fst==0){
			if(v[i].snd>0){
				cant.upd(v[i].snd,1);
				val.upd(v[i].snd,ump[v[i].snd]);
				sum+=ump[v[i].snd];
			}else{
				cant.upd(-v[i].snd,-1);
				val.upd(-v[i].snd,-ump[-v[i].snd]);
				sum-=ump[-v[i].snd];
			}
		}else{
			if(v[i].snd>0){
				cant.upd(v[i].snd,1);
				cantl.upd(v[i].snd,1);
				val.upd(v[i].snd,ump[v[i].snd]);
				sum+=ump[v[i].snd];
				cl++;
			}else{
				cant.upd(-v[i].snd,-1);
				cantl.upd(-v[i].snd,-1);
				val.upd(-v[i].snd,-ump[-v[i].snd]);
				sum-=ump[-v[i].snd];
				cl--;
			}
		}
	/*	fore(i,0,5)cout<<cant.query(i,i+1)<<" "; cout<<"\n";
		fore(i,0,5)cout<<cantl.query(i,i+1)<<" "; cout<<"\n";
		fore(i,0,5)cout<<val.query(i,i+1)<<" "; cout<<"\n";*/
		cout<<solve()<<"\n";
	}
	
	return 0;
}