#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp(a,b) {a,b}

using namespace std;
typedef long long ll;

ll MOD=998244353;

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

//ll fact[10004];
ll c[5010][5010];
ll inv[10004];
ll comb(ll x, ll y){
	if(c[x][y]!=0)return c[x][y];
	if(y==0||y==x){
		c[x][y]=1; return 1;
	}
	c[x][y]=(comb(x-1,y)+comb(x-1,y-1));
	if(c[x][y]>MOD)c[x][y]-=MOD;
	return c[x][y];
	/*ll res=fact[x];
	res*=be(fact[y],MOD-2,MOD); res%=MOD;
	res*=be(fact[x-y],MOD-2,MOD); res%=MOD;*/
}

ll formula(ll n, ll m, ll k){
	//cout<<"formulando "<<n<<" "<<m<<" "<<k<<"\n";
	ll res=0;
	fore(i,0,n+1){
		ll t=(inv[n-i]*comb(n,i))%MOD;
		t*=be(i,k,MOD); t%=MOD;
		res+=t; res%=MOD;
	}
	return (res*be(m,(MOD-2)*n,MOD))%MOD;
}

ll prod(ll x, ll l, ll s){
	//cout<<"productando "<<x<<" "<<l<<" "<<s<<"\n";
	ll res=1;
	fore(i,1,l+1){
		if(i==s)continue;
		res*=(x-i); res%=MOD;
		res+=MOD;
		if(res>MOD)res-=MOD;
	}
	return res;
}

ll solve(ll n, ll m, ll k){
	//cout<<"solveando "<<n<<" "<<m<<" "<<k<<"\n";
	ll res=0;
	fore(i,1,k+2){
		ll t=be(prod(i,k+1,i),MOD-2,MOD);
		t*=prod(n,k+1,i); t%=MOD;
		t*=formula(i,m,k); t%=MOD;
		res+=t; res%=MOD;
	}
	return res;
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	//fact[0]=1;
	//fore(i,1,10004)fact[i]=(i*fact[i-1])%MOD;
	fore(i,0,10004)inv[i]=be(m-1,i,MOD);
	//cout<<fact[n]<<" "<<comb(n,m)<<"\n";
	if(n<=k+1)cout<<formula(n,m,k);
	else cout<<solve(n,m,k);
	return 0;
}