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

const int MAXN=500009;

ll a[MAXN],b[MAXN];

set<ll> s;
ll val[MAXN];

vector<ll> comp(vector<ll> v){
	s.clear();
	for(auto i:v)s.insert(i);
	//fore(i,0,SZ(s))val[i]=0;
	ll va=0;
	for(auto i:s){
		val[va]=i;
		va++;
	}
	fore(i,0,SZ(v)){
		v[i]=lower_bound(val,val+va,v[i])-val;
	}
	return v;
}

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

STree st(MAXN);

ll lis(vector<ll> v){
	//cout<<"lis ";
	//for(auto i:v)cout<<i<<" ";
	//cout<<" -> ";
	v=comp(v);
	fore(i,0,SZ(v))st.upd(i,0);
	fore(i,0,SZ(v)){
		st.upd(v[i],st.query(0,v[i]+1)+1);
	}
	//cout<<st.query(0,SZ(v))<<"\n";
	return st.query(0,SZ(v));
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,1,n+1)cin>>a[i];
	a[0]=-1e18,a[n+1]=1e18;
	fore(i,1,k+1)cin>>b[i];
	b[0]=0; b[k+1]=n+1;
	n+=2; k+=2;
	fore(i,0,n)a[i]-=i;
	fore(i,0,k-1){
		if(a[b[i+1]]-a[b[i]]<0){
			cout<<"-1\n";
			return 0;
		}
	}
	ll res=0;
	fore(i,0,k-1){
		vector<ll> va;
		fore(j,b[i]+1,b[i+1]){
			if(a[j]>=a[b[i]]&&a[j]<=a[b[i+1]]){
				va.pb(a[j]);
			}else{
				res++;
				//cout<<"+ j\n";
			}
		}
		res+=SZ(va)-lis(va);
	}
	cout<<res<<"\n";
	
	return 0;
}