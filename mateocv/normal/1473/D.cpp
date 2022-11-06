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

pair<ll,ll> oper(pair<ll,ll> a, pair<ll,ll> b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}

const pair<ll,ll> NEUT={9e18,-9e18};
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

const int MAXN=200005;

STree st(MAXN);

ll sum[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		string s; cin>>s;
		sum[0]=0;
		fore(i,0,SZ(s)){
			sum[i+1]=sum[i]+((s[i]=='+')?1:-1);
		}
		//fore(i,0,n+1)cout<<sum[i]<<" ";
		//cout<<"\n";
		fore(i,0,n+1)st.upd(i,{sum[i],sum[i]});
		while(m--){
			ll l,r; cin>>l>>r;
			ll sal=sum[l-1]-sum[r];
			ll maxi=max(st.query(0,l).snd,st.query(r+1,n+1).snd+sal);
			ll mini=min(st.query(0,l).fst,st.query(r+1,n+1).fst+sal);
			//cout<<l<<" "<<r<<" "<<sal<<" "<<maxi<<" "<<mini<<"\n";
			cout<<maxi-mini+1<<"\n";
		}
	}
	
	return 0;
}