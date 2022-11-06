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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll sum=0;
	fore(i,0,n)sum+=a[i];
	ll t[n];
	mset(t,0);
	STree st(n);
	fore(i,0,n)st.upd(i,0);
	ll q; cin>>q;
	map<pair<ll,ll>,ll> mp;
	ll ss,tt,uu;
	while(q--){
		cin>>ss>>tt>>uu;
		if(mp.count({ss,tt})){
			t[mp[{ss,tt}]]--;
			if(t[mp[{ss,tt}]]<=a[mp[{ss,tt}]])st.upd(mp[{ss,tt}],t[mp[{ss,tt}]]);
			mp.erase({ss,tt});
		}
		if(uu!=0){
			mp[{ss,tt}]=uu-1;
			t[mp[{ss,tt}]]++;
			if(t[mp[{ss,tt}]]<=a[mp[{ss,tt}]])st.upd(mp[{ss,tt}],t[mp[{ss,tt}]]);
		}
		cout<<sum-st.query(0,n)<<"\n";
	}
	
	return 0;
}