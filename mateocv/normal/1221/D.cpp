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

ll a[300005],b[300005];
ll dp[300005][10];
ll nn;

ll f(ll n, ll bo){
	ll &r=dp[n][bo];
	if(r>=0)return r;
	if(n==0){
		if(a[0]==a[1]+bo){
			r=b[0];
		}else r=0;
		return r;
	}
	r=1e18;
	fore(j,0,10){
		if((n==nn-1||a[n]+j!=a[n+1]+bo)){
			r=min(r,f(n-1,j)+j*b[n]);
		}
	}
	return r;
}

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n; nn=n;
		fore(i,0,n)cin>>a[i]>>b[i];
		fore(i,0,n){
			fore(j,0,10){
				dp[i][j]=-1;
			}
		}
		if(n==1){
			cout<<0<<"\n";
		}else{
			cout<<f(n-1,0)<<"\n";	
		}
	}
	
	return 0;
}