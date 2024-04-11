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
#define oper1 min
const ll NEUT1=9e18;
struct STree1 { // [cerrado-abierto)
    vector<ll> st;int n;
    STree1(int n): st(4*n+5,NEUT1), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper1(st[2*k],st[2*k+1]);
    }
    ll query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT1;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper1(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper2 max
const ll NEUT2=-9e18;
struct STree2 { // [cerrado-abierto)
    vector<ll> st;int n;
    STree2(int n): st(4*n+5,NEUT2), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper2(st[2*k],st[2*k+1]);
    }
    ll query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT2;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper2(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

int main(){FIN;
	ll d=0;
	ll n; cin>>n;
	pair<pair<ll,ll>,pair<ll,ll>> a[n];
	fore(i,0,n)cin>>a[i].fst.fst>>a[i].fst.snd>>a[i].snd.fst>>a[i].snd.snd;
	STree1 st1(n);
	STree2 st2(n);
	sort(a,a+n);
	fore(i,0,n){
		st1.upd(i,a[i].snd.snd);
		st2.upd(i,a[i].snd.fst);
	}
	fore(i,0,n){
		auto it=lower_bound(a,a+n,make_pair(make_pair(a[i].fst.fst,a[i].fst.fst),make_pair(0ll,0ll)));
		auto itt=upper_bound(a,a+n,make_pair(make_pair(a[i].fst.snd+1,a[i].fst.snd),make_pair(0ll,0ll)));
		ll s=it-a,e=itt-a;
		//cout<<s<<" "<<e<<"\n";
		//cout<<st1.query(s,e)<<" "<<st2.query(s,e)<<"\n";
		if(st1.query(s,e)<a[i].snd.fst&&1/*nada*/){
			cout<<"NO"; 
			if(d)cout<<1;
			return 0;
		}
		if(st2.query(s,e)>a[i].snd.snd&&1/*nada2*/){
			cout<<"NO";
			if(d)cout<<2<<" "<<i;
			return 0;
		}
	}
	fore(i,0,n)swap(a[i].fst.fst,a[i].fst.snd);
	sort(a,a+n);
	fore(i,0,n){
		st1.upd(i,a[i].snd.snd);
		st2.upd(i,a[i].snd.fst);
	}
	fore(i,0,n){
		auto it=lower_bound(a,a+n,make_pair(make_pair(a[i].fst.fst,-1ll),make_pair(0ll,0ll)));
		auto itt=upper_bound(a,a+n,make_pair(make_pair(a[i].fst.snd+1,-1ll),make_pair(0ll,0ll)));
		ll s=it-a,e=itt-a;
		if(st1.query(s,e)<a[i].snd.fst&&1/*nada*/){
			cout<<"NO"; 
			if(d)cout<<3;
			return 0;
		}
		if(st2.query(s,e)>a[i].snd.snd&&1/*nada2*/){
			cout<<"NO"; 
			if(d)cout<<4;
			return 0;
		}
	}
	fore(i,0,n)swap(a[i].fst.fst,a[i].fst.snd);
	fore(i,0,n)swap(a[i].fst.fst,a[i].snd.fst);
	fore(i,0,n)swap(a[i].fst.snd,a[i].snd.snd);
	sort(a,a+n);
	fore(i,0,n){
		st1.upd(i,a[i].snd.snd);
		st2.upd(i,a[i].snd.fst);
	}
	fore(i,0,n){
		auto it=lower_bound(a,a+n,make_pair(make_pair(a[i].fst.fst,a[i].fst.fst),make_pair(0ll,0ll)));
		auto itt=upper_bound(a,a+n,make_pair(make_pair(a[i].fst.snd+1,a[i].fst.snd),make_pair(0ll,0ll)));
		ll s=it-a,e=itt-a;
		if(st1.query(s,e)<a[i].snd.fst&&1/*nada*/){
			cout<<"NO"; 
			if(d)cout<<5;
			return 0;
		}
		if(st2.query(s,e)>a[i].snd.snd&&1/*nada2*/){
			cout<<"NO"; 
			if(d)cout<<6;
			return 0;
		}
	}
	fore(i,0,n)swap(a[i].fst.fst,a[i].fst.snd);
	sort(a,a+n);
	fore(i,0,n){
		st1.upd(i,a[i].snd.snd);
		st2.upd(i,a[i].snd.fst);
	}
	fore(i,0,n){
		auto it=lower_bound(a,a+n,make_pair(make_pair(a[i].fst.fst,-1ll),make_pair(0ll,0ll)));
		auto itt=upper_bound(a,a+n,make_pair(make_pair(a[i].fst.snd+1,-1ll),make_pair(0ll,0ll)));
		ll s=it-a,e=itt-a;
		if(st1.query(s,e)<a[i].snd.fst&&1/*nada*/){
			cout<<"NO"; 
			if(d)cout<<7;
			return 0;
		}
		if(st2.query(s,e)>a[i].snd.snd&&1/*nada2*/){
			cout<<"NO";
			if(d)cout<<8;
			 return 0;
		}
	}
	cout<<"YES";
	return 0;
}