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

const int MAXN=200005;

ll a[MAXN],b[MAXN],u[MAXN];

ll MOD=998244353;

/*----------------CLASSIC SEGMENT TREE----------------*/
ll INF=9e18;
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

STree st(MAXN);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,k)cin>>b[i],b[i]--;
		fore(i,0,n){
			u[a[i]]=i;
		}
		fore(i,0,n)a[i]=u[a[i]];
		fore(i,0,k)b[i]=u[b[i]];
		//fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";
		//fore(i,0,k)cout<<b[i]<<" "; cout<<"\n";
		fore(i,0,n)st.upd(i,i+1);
		fore(i,0,k)st.upd(b[i],INF);
		ll res=1;
		//fore(i,0,n)cout<<st.query(i,i+1)<<" "; cout<<"\n";
		fore(i,0,k){
			//cout<<i<<":\n";
			ll va=0,pos=-1;
			if(b[i]-1>=0){
				ll l=0,r=b[i];
				while(l<=r){
					ll m=(l+r)/2;
					if(st.query(b[i]-m,b[i])==INF)r=m-1;
					else l=m+1;
				}
				auto q=st.query(b[i]-r,b[i]);
				if(0<q&&q<INF){
					va++;
					pos=q;
				}
			}
			if(b[i]+1<n){
				ll l=0,r=n-b[i]-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(st.query(b[i]+1,b[i]+1+m)>0)r=m-1;
					else l=m+1;
				}
				auto q=st.query(b[i]+1,b[i]+1+l);
				if(0<q&&q<INF){
					va++;
					pos=q;
				}
			}
			//cout<<va<<" "<<pos<<"\n";
			res=res*va%MOD;
			st.upd(b[i],b[i]+1);
			st.upd(pos-1,0);
			//fore(i,0,n)cout<<st.query(i,i+1)<<" "; cout<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}