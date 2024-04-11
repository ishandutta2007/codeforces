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

const int MAXN=400005;
ll MOD=1000000007;

ll a[MAXN],fact[MAXN],facti[MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
}

ll c[MAXN],sump[MAXN];

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,MAXN)facti[i]=fpow(fact[i],MOD-2)%MOD;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,2*n)c[i]=0;
		fore(i,0,n)c[a[i]]++;
		fore(i,0,2*n+1)sump[i]=0;
		fore(i,0,2*n)sump[i+1]=sump[i]+c[i];
		ll res=0;
		fore(i,0,n){
			if(c[i]){
				ll sum=sump[i+k+1]-sump[i];
				fore(j,1,min(c[i],m)+1){
					res=(res+comb(c[i],j)*comb(sum-c[i],m-j))%MOD;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}