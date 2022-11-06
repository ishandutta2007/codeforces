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
#define oper min
const pair<ll,ll> NEUT={9e18,9e18};
struct STree { // [cerrado-abierto)
    vector<pair<ll,ll>> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]={v,s};return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    pair<ll,ll> query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

int main(){FIN;
	ll q,x; cin>>q>>x;
	STree st(x);
	fore(i,0,x)st.upd(i,0);
	fore(i,0,q){
		ll y; cin>>y;
		st.upd(y%x,st.query(y%x,(y%x)+1).fst+1);
		pair<ll,ll> s=st.query(0,x);
		//cout<<s.fst<<" "<<s.snd<<"\n";
		cout<<x*(s.fst)+s.snd<<"\n";
	}
	return 0;
}