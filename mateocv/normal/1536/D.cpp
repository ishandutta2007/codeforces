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

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define oper min
#define NEUT 1e9
struct STree{
	vector<int> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, int value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

const int MAXN=200005;

STree st(MAXN);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>> v;
		vector<ll> a(n);
		fore(i,0,n){
			cin>>a[i];
			v.pb({a[i],i});
		}
		sort(ALL(v));
		map<ll,ll> uv;
		vector<ll> ui(n);
		fore(i,0,n){
			ui[v[i].snd]=i;
			st.upd(i,v[i].snd);
			if(!uv.count(v[i].fst))uv[v[i].fst]=i;
		}
		//fore(i,0,n)cout<<st.query(i,i+1)<<" ";
		//cout<<"\n";
		ll br=0;
		fore(i,0,n-1){
			ll l=-1,r=-1;
			if(a[i]<a[i+1]){
				l=ui[i]+1,r=uv[a[i+1]];
			}else{
				l=ui[i+1]+1,r=uv[a[i]];
			}
			auto q=st.query(l,r);
			if(q<i)br++;
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}