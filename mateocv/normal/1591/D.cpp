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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<ll> c(n);
		for(auto i:a)c[i]++;
		ll br=0;
		fore(i,0,n){
			if(c[i]>=2)br++;
		}
		if(br){
			cout<<"YES\n";
			continue;
		}
		vector<ll> u(n);
		fore(i,0,n)u[a[i]]=i;
		STree st(n);
		ll cant=0;
		fore(i,0,n){
			cant+=st.query(u[i],n);
			st.upd(u[i],1);
		}
		if(cant&1)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}