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
#define oper(a,b) {a.fst+b.fst,{min(a.snd.fst,a.fst+b.snd.fst),max(a.snd.snd,a.fst+b.snd.snd)}}
const pair<ll,pair<ll,ll>> NEUT={0,{9e18,-9e18}};
struct STree { // [cerrado-abierto)
    vector<pair<ll,pair<ll,ll>>> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, pair<ll,pair<ll,ll>> v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    pair<ll,pair<ll,ll>> query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,{v,{v,v}});}
    pair<ll,pair<ll,ll>> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

ll dist(char a, char b){
	string s=")_(";
	ll posa=-1,posb=-1;
	fore(k,0,3){
		if(s[k]==a)posa=k;
		if(s[k]==b)posb=k;
	}
	return posb-posa;
}

STree st(1000005);

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll va=0;
	ll res=0;
	fore(i,0,n){
		if(s[i]=='L')va=max(0ll,va-1),cout<<res<<" ";
		else if(s[i]=='R')va++,cout<<res<<" ";
		else{
			if(s[i]!='('&&s[i]!=')')s[i]='_';
			st.upd(va,dist('_',s[i]));
			pair<ll,pair<ll,ll>> q=st.query(0,1000005);
			res=(q.snd.fst<0||q.fst!=0)?-1:q.snd.snd;
			cout<<res<<" ";
		}
	}
	
	return 0;
}