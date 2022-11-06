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

ll n; 
ll a[6];
ll b[200005];

vector<pair<ll,ll>> v;

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper min
const ll NEUT=9e18;
struct STree { // [cerrado-abierto)
    vector<ll> st;int n;
    STree(int n): st(4*n+5,0), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]+=v;return;}
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

STree st(200005);

int main(){FIN;
	fore(i,0,6)cin>>a[i];
	cin>>n;
	fore(i,0,n)cin>>b[i];
	fore(i,0,n){
		fore(j,0,6){
			v.pb({b[i]-a[j],i});
		}
	}
	sort(ALL(v));
	//fore(i,0,SZ(v))cout<<i<<" "<<v[i].fst<<" "<<v[i].snd<<"\n";
	ll l=0,r=-1,res=9e18;
	while(1){
		//cout<<l<<" "<<r<<" "<<res<<"\n";
		//fore(i,0,6)cout<<cant[i]<<" "; cout<<"\n";
		if(st.query(0,n)>0){
			res=min(res,v[r].fst-v[l].fst);
			st.upd(v[l].snd,-1);
			l++;
		}else{
			r++;
			if(r==SZ(v))break;
			st.upd(v[r].snd,1);
		}
	}
	cout<<res<<"\n";
	return 0;
}