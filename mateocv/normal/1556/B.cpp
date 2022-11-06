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

ll INF=1e18;

#define oper(a,b) a+b
#define NEUT 0
struct STree{
	vector<int> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
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

STree st(100005);

ll solve(vector<ll> p){
	fore(i,0,SZ(p))st.upd(i,1);
	ll res=0;
	for(auto i:p){
		res+=st.query(0,i);
		st.upd(i,0);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]=(a[i]&1);
		ll res=INF;
		fore(k,0,2){
			vector<ll> p;
			ll pos[2]={k,k^1};
			fore(i,0,n){
				p.pb(pos[a[i]]);
				pos[a[i]]+=2;
			}
			ll br=0;
			for(auto i:p){
				if(i>=n)br++;
			}
			if(br)continue;
			res=min(res,solve(p));
		}
		if(res<INF)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}