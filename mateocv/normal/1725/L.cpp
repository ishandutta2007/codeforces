#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define oper(a,b) (a+b)
#define NEUT 0
struct STree{
	vector<int> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, int v){
		p+=n;
		for(t[p]=v;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
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
	int n; cin>>n;
	vector<ll> a(n);
	ll s=0,mx=-1e18,mn=1e18;
	
	fore(i,0,n){
		int x; cin>>x; s+=x; a[i]=s,mx=max(mx,s),mn=min(mn,s);
	}
	
	if(mn<0 || a.back()!=mx){
		cout<<"-1\n";
		exit(0);
	}
	
	vector<pair<ll,int>> b;
	fore(i,0,n) b.pb({-a[i],-i});
	sort(ALL(b));
	
	STree st(n);
	
	ll ans=0;
	for(auto x:b) ans+=st.query(0,-x.snd),st.upd(-x.snd,1);
	
	cout<<ans<<"\n";
	
}