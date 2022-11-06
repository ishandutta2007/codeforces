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

ll dp[200005];
ll n,k;
string s;
STree st(200005);

/*void com(){
	fore(i,0,n){
		if(s[i]=='1')st.upd(i,i+1);
	}
}*/

ll f(ll x){
	if(x<0)return 0;
	ll &r=dp[x];
	if(r>=0)return r;
	ll q=st.query(max(x-k,0ll),min(x+k+1,n));
	if(q==NEUT){
		r=x+1+f(x-1); return r;
	}
	r=min(q+f(q-2-k),x+1+f(x-1));
	return r;
}

int main(){FIN;
	cin>>n>>k;
	cin>>s;
	mset(dp,-1);
	fore(i,0,n){
		if(s[i]=='1')st.upd(i,i+1);
	}
	//ll va=n-1;
	//ll res=0;
	/*while(1){
		if(va<0)break;
		ll q=st.query(max(va-k,0ll),min(va+k+1,n));
		if(q==NEUT){
			res+=va+1;
			va--;
			continue;
		}else{
			res+=q;
			va=q-2-k;
		}
	}*/
	//fore(i,0,n)cout<<f(i)<<" "; cout<<"\n";
	cout<<f(n-1);
	return 0;
}