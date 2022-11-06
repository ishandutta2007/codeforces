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

const int MAXN=200005;

const ll MOD=1000000007;

ll fact[MAXN],facti[MAXN];

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

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,MAXN)facti[i]=fpow(fact[i],MOD-2);
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r;
		ll mini=min(abs(l-1),abs(r-n));
		ll maxi=min(abs(r-1),abs(l-n));
		ll res=(1+(n&1))*mini*comb(n,n/2)%MOD;
		ll a=0,b=0;
		ll li=1,ri=n;
		while(1){
			//cout<<mini<<" "<<a<<" "<<b<<" "<<li<<" "<<ri<<"\n";
			mini++;
			if(mini>maxi)break;
			if(abs(l-li)<mini)li++,a++;
			if(abs(r-ri)<mini)ri--,b++;
			if(a>(n+1)/2||b>(n+1)/2)break;
			//cout<<mini<<" "<<a<<" "<<b<<" "<<li<<" "<<ri<<"\n";
			if(n/2-a>=0){
				//cout<<"HOLAAA1 "<<n-a-b<<" "<<n/2-a<<"\n";
				res=add(res,comb(n-a-b,n/2-a)%MOD);
			}
			if((n&1)&&(n+1)/2-a>=0){
				//cout<<"HOLAAA2 "<<n-a-b<<" "<<(n+1)/2-a<<"\n";
				res=add(res,comb(n-a-b,(n+1)/2-a)%MOD);
			}
			//cout<<mini<<" "<<a<<" "<<b<<" "<<li<<" "<<ri<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}