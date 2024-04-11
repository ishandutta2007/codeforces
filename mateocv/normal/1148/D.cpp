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
#define oper max
const ll NEUT=-1;
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
	pair<ll,ll> p[n];
	fore(i,0,n)cin>>p[i].fst>>p[i].snd;
	vector<pair<ll,ll>> sub;
	vector<pair<ll,ll>> baj;
	fore(i,0,n){
		if(p[i].fst>p[i].snd)baj.pb(p[i]);
		if(p[i].fst<p[i].snd)sub.pb(p[i]);
	}
	map<ll,ll>m;
	fore(i,0,n){
		m[p[i].snd]=i;
		m[p[i].fst]=i;
	}
	//ll res=0;
	vector<ll> res1;
	vector<ll> res2;
	// Primera parte
	sort(ALL(sub));
	STree st1(2*n+5);
	fore(i,0,SZ(sub)){
		st1.upd(sub[i].fst,sub[i].snd);
	}
	ll maxi=9e18-1;
	while(1){
		//ll i=*(upper_bound(make_pair(maxi,0)));
		ll q=st1.query(0,min(maxi,2*n+1));
		//cout<<q<<endl;
		if(q!=-1){
			res1.pb(m[q]+1);
			//cout<<"Metiendo "<<m[q]<<" a res1"<<endl;
			maxi=q;
			st1.upd(p[m[q]].fst,-1);
		}else{
			break;
		}
	}
	//Segundo parte
	fore(i,0,SZ(baj)){
		swap(baj[i].fst,baj[i].snd);
	}
	sort(ALL(baj));
	STree st2(2*n+5);
	fore(i,0,SZ(baj)){
		st2.upd(baj[i].fst,baj[i].snd);
	}
	maxi=9e18-1;
	while(1){
		//ll i=*(upper_bound(make_pair(maxi,0)));
		ll q=st2.query(0,min(maxi,2*n+1));
		//cout<<"Hasta "<<min(maxi,n)<<" dio "<<q<<endl;
		if(q!=-1){
			res2.pb(m[q]+1);
			//cout<<"Metiendo "<<m[q]<<" a res2"<<endl;
			maxi=q;
			st2.upd(p[m[q]].snd,-1);
		}else{
			break;
		}
	}
	
	if(SZ(res1)>SZ(res2)){
		cout<<SZ(res1)<<"\n";
		fore(i,0,SZ(res1))cout<<res1[i]<<" ";
	}else{
		reverse(ALL(res2));
		cout<<SZ(res2)<<"\n";
		fore(i,0,SZ(res2))cout<<res2[i]<<" ";
	}
	
	
	return 0;
}