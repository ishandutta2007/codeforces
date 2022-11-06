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

ll cant[62];
ll a[500005];
ll pot[62],pott[62];

ll MOD=1000000007;

ll add(ll x, ll y){
	ll res=x+y;
	if(res>=MOD)res-=MOD;
	return res;
}

int main(){FIN;
	fore(i,0,60){
		pot[i]=(1ll<<i)%MOD;
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		mset(cant,0);
		fore(i,0,n){
			fore(j,0,60){
				if((1ll<<j)&a[i])cant[j]=add(cant[j],pot[j]);
			}
		}
		fore(i,0,60)pott[i]=pot[i]*n%MOD;
		ll res=0;
		fore(i,0,n){
			ll sum[2]={0,0};
			fore(j,0,60){
				if((1ll<<j)&a[i]){
					sum[0]=add(sum[0],cant[j]);
					sum[1]=add(sum[1],pott[j]);
				}else{
					sum[1]=add(sum[1],cant[j]);
				}
			}
			res=(res+sum[0]*sum[1])%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}