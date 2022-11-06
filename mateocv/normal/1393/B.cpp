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
#define oper max
const pair<ll,ll> NEUT={0,0};
struct STree { // [cerrado-abierto)
    vector<pair<ll,ll>> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, pair<ll,ll> v){
        if(s+1==e){st[k]=v;return;}
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
    void upd(int p, pair<ll,ll> v){upd(1,0,n,p,v);}
    pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

STree st(100005);

void solve(){
	auto q=st.query(0,100005);
	st.upd(q.snd,NEUT);
	auto qq=st.query(0,100005);
	st.upd(qq.snd,NEUT);
	auto qqq=st.query(0,100005);
	//cout<<q.fst<<" "<<qq.fst<<" "<<qqq.fst<<"\n";
	if(q.fst>=8||(q.fst>=6&&qq.fst>=2)||(q.fst>=4&&qq.fst>=4)||(q.fst>=4&&qq.fst>=2&&qqq.fst>=2)){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	if(qq.snd)st.upd(qq.snd,qq);
	if(q.snd)st.upd(q.snd,q);
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		auto qq=st.query(a[i],a[i]+1);
		st.upd(a[i],{qq.fst+1,a[i]});
	}
	ll q; cin>>q;
	while(q--){
		char c; cin>>c;
		if(c=='+'){
			ll x; cin>>x;
			auto qq=st.query(x,x+1);
			st.upd(x,{qq.fst+1,x});
		}
		if(c=='-'){
			ll x; cin>>x;
			auto qq=st.query(x,x+1);
			st.upd(x,{qq.fst-1,x});
		}
		solve();
	}
	
	return 0;
}