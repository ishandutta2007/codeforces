#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper max
const ll NEUT=0;
struct STree { // [cerrado-abierto)
    vector<ll> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]=v;return;}
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

vector<pair<ll,ll>> t;
ll v[100005];
STree st(100005);

ll f(ll i){
	ll r=st.query(0,i)+v[i];
	st.upd(i,r); return r;
}

int main(){FIN;
	ll n; cin>>n;
	ll r[n],h[n];
	fore(i,0,n)cin>>r[i]>>h[i];
	fore(i,0,n)v[i]=r[i]*r[i]*h[i];
	fore(i,0,n)t.pb({v[i],-i});
	sort(ALL(t));
	ll res=0;
	fore(i,0,n){
		res=max(res,f(-t[i].snd));
	}
	cout<<fixed<<setprecision(10)<<acos(-1)*res;
	return 0;
}