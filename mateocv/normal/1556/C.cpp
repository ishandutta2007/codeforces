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
#define NEUT 1e18
struct STree{
	vector<ll> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, ll value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){ // [l, r)
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

STree st(1010);

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> sump={0};
	fore(i,0,n)sump.pb(sump.back()+(i&1?-a[i]:a[i]));
	//for(auto i:sump)cout<<i<<" ";
	//cout<<"\n";
	fore(i,0,n+1)st.upd(i,sump[i]);
	ll res=0;
	fore(i,0,n){
		if(i&1)continue;
		fore(j,i+1,n){
			if(!(j&1))continue;
			//cout<<i<<" "<<j<<":\n";
			ll l=1,r=1;
			ll ab=-(st.query(i+1,j+1)-sump[i+1]);
			//cout<<ab<<"\n";
			l=max(l,ab);
			r=max(r,sump[j]-sump[i+1]+ab);
			res+=max(0ll,min(a[i]-l+1,a[j]-r+1));
			//cout<<max(0ll,min(a[i]-l+1,a[j]-r+1))<<"\n";
		}
	}
	cout<<res<<"\n";
	
	return 0;
}