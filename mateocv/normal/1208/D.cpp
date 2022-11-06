#include <bits/stdc++.h>
#define pb push_back
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
#define oper(a,b) a+b
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


int main(){FIN;
	ll n; cin>>n;
	ll s[n];
	fore(i,0,n)cin>>s[i];
	STree st(n);
	fore(i,0,n)st.upd(i,i);
	vector<ll> res;
	set<ll> ss;
	fore(i,0,n)ss.insert(i);
	fore(i,0,n){
		ll l=0,r=n-1;
		while(l<=r){
	 		ll m=(l+r)/2;
			if(st.query(0,m+1)>=s[n-1-i])r=m-1;
	  		else l=m+1;
		}
		//cout<<l<<" ";
		auto it=ss.lower_bound(l);
		l=*it;
		//cout<<l<<"\n";
		//fore(i,0,n)cout<<st.query(i,i+1)<<" "; cout<<"\n";
		//for(auto i:ss)cout<<i<<" "; cout<<"\n";
		res.pb(l+1);
		st.upd(l+1,0);
		ss.erase(l);
	}
	reverse(ALL(res));
	fore(i,0,n)cout<<res[i]<<" ";
	return 0;
}