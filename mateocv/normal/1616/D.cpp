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

ll dp[50004][2];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll x; cin>>x;
		fore(i,0,n)a[i]-=x;
		//for(auto i:a)cout<<i<<" ";
		//cout<<"\n";
		vector<ll> sump={0};
		fore(i,0,n)sump.pb(sump.back()+a[i]);
		STree st(n+1);
		fore(i,0,n+1)st.upd(i,sump[i]);
		vector<ll> maxr(n);
		fore(i,0,n){
			ll s=sump[i];
			ll l=i+1,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(st.query(i+2,m+2)<s)r=m-1;
				else l=m+1;
			}
			maxr[i]=r;
		}
		//for(auto i:maxr)cout<<i<<" ";
		//cout<<"\n";
		STree stm(n),st0(n+1);
		fore(i,0,n)stm.upd(i,maxr[i]);
		for(ll i=n;i>=0;i--){
			//cout<<i<<":\n";
			if(i==n){
				dp[i][0]=0;
				dp[i][1]=0;
				st0.upd(i,-n);
			}else{
				dp[i][0]=max(dp[i+1][0],dp[i+1][1]);
				st0.upd(i,-dp[i][0]-i);
				ll l=i+1,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(stm.query(i,m+1)>=m)l=m+1;
					else r=m-1;
				}
				//cout<<r<<"\n";
				dp[i][1]=-st0.query(i+1,r+2)-i;
			}
			//cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		}
		cout<<max(dp[0][0],dp[0][1])<<"\n";
	}
	
	return 0;
}