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

pair<ll,ll> calc(ll i, ll b){
	return {i/(b+1)+1,b==0?n:i/b};
}

#define oper min
#define NEUT {1e9,-1}
struct STree{
	vector<pair<ll,ll>> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, pair<ll,ll> value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	pair<ll,ll> query(int l, int r){ // [l, r)
		pair<ll,ll> res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<pair<pair<ll,ll>,ll>> v;
		fore(i,0,n)v.pb({calc(i+1,a[i]),i});
		sort(ALL(v));
		//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<endl;
		STree st(n);
		vector<ll> res(n,-1);
		ll ul=0;
		fore(i,1,n+1){
			while(ul<n&&v[ul].fst.fst<=i){
				st.upd(v[ul].snd,{v[ul].fst.snd,v[ul].snd});
				ul++;
			}
			auto q=st.query(0,n);
			//cout<<i<<" "<<q.fst<<" "<<q.snd<<endl;
			assert(i<=q.fst);
			res[q.snd]=i;
			st.upd(q.snd,NEUT);
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}