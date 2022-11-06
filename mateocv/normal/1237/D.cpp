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

const ll INF=1e18;

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper min
const ll NEUT=9e18;
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
	ll a[2*n];
	fore(i,0,n)cin>>a[i],a[n+i]=a[i];
	STree st(2*n);
	fore(i,0,2*n){
		st.upd(i,a[i]);
	}
	pair<ll,ll> b[n];
	fore(i,0,n){
		b[i].fst=a[i];
		b[i].snd=i;
	}
	sort(b,b+n);
	reverse(b,b+n);
	//fore(i,0,n)cout<<b[i].fst<<" "<<b[i].snd<<"\n";
	set<ll> s;
	s.insert(INF);
	ll res[2*n];
	mset(res,-1);
	//cout<<st.query(0,4)<<"\n";
	fore(i,0,n){
		ll h=INF;
		if(SZ(s)){
			h=*s.lower_bound(b[i].snd);
		}
		//cout<<h<<"\n";
		ll l=b[i].snd+1,r=min(b[i].snd+n,h);
		while(l <= r) {
		  ll m = (l+r)/2;
		  //cout<<l<<" "<<r<<" "<<m<<" "<<st.query(b[i].snd,m)<<"\n";
		  if(st.query(b[i].snd,m)*2<b[i].fst) r=m-1;
		  else l=m+1;
		}
		//cout<<l<<" "<<r<<"\n";
		if(i==0){
			if(r>=b[i].snd+n){
				res[b[i].snd]=INF;
				res[b[i].snd+n]=INF;
				s.insert(b[i].snd); s.insert(b[i].snd+n);
				continue;
			}
		}
		if(r>=h){
			if(res[h]==INF){
				res[b[i].snd]=INF;
				res[b[i].snd+n]=INF;
			}else{
				res[b[i].snd]=h-b[i].snd+res[h];
				res[b[i].snd+n]=h-b[i].snd+res[h];
			}
		}else{
			res[b[i].snd]=r-b[i].snd;
			res[b[i].snd+n]=r-b[i].snd;
		}
		s.insert(b[i].snd); s.insert(b[i].snd+n);
	}
	fore(i,0,n){
		if(res[i]==INF){
			res[i]=-1;
		}
	}
	fore(i,0,n)cout<<res[i]<<" ";
	
	return 0;
}