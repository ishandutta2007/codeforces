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
		for(t[p += n]+=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
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

STree st(200005);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n+1)st.upd(i,-st.query(i,i+1));
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> c(n+1);
		fore(i,0,n)c[a[i]]++;
		fore(i,0,n+1){
			st.upd(i,c[i]>0);
		}
		ll pos=0;
		vector<ll> res;
		while(pos<n){
			/*
			cout<<pos<<":"<<endl;
			fore(i,0,n)cout<<c[i]<<" "; 
			cout<<"\n";
			fore(i,0,n+1)cout<<st.query(i,i+1)<<" ";
			*/
			//cout<<endl;
			ll l=0,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(st.query(0,m)==m)l=m+1;
				else r=m-1;
			}
			//cout<<l<<" "<<r<<endl;
			res.pb(r);
			//cout<<r<<endl;
			if(r==0){
				c[a[pos]]--;
				if(c[a[pos]]==0)st.upd(a[pos],-1);
				pos++;
			}else{
				vector<ll> vis(r);
				ll cant=0;
				while(pos<n&&cant<r){
					if(a[pos]<r&&!vis[a[pos]]){
						vis[a[pos]]++;
						cant++;
					}
					c[a[pos]]--;
					if(c[a[pos]]==0)st.upd(a[pos],-1);
					pos++;
				}
			}
			//cout<<"npos "<<pos<<endl;

		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}