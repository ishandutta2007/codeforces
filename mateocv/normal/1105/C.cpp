#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

ll fac[200005];

ll fact(ll x){
	if(fac[x]>=0){
		return fac[x];
	}
	if(x==0){
		fac[0]=1;
		return fac[0];
	}
	fac[x]=(fact(x-1)*x)%(1000000007);
	return fac[x];
}

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll comb(ll x, ll y, ll mod){
	ll res=(fact(x-y)*fact(y))%(mod);
	res=(fact(x)*(be(res,mod-2,mod)))%mod;
	return res;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, l, r; cin>>n>>l>>r;
	ll MOD=1e9+7,DIV=333333336;
	memset(fac, -1, sizeof fac);
	ll largo=r-l+1;
	if(largo%3==0){
		cout<<(be(largo,n,MOD)*DIV)%MOD;
	}else
	if(largo%3==1){
		cout<<(((be(largo,n,MOD)-1)*DIV)%MOD+((l*n)%3==0))%MOD;
	}else
	if(largo%3==2){
		int res=((be(largo,n,MOD)-be(2,n,MOD))*DIV)%MOD;
//		int rest=(n*l)%3;
		for(int i=0;i<=n;i++){
			if((n*l+i)%3==0){
				res+=comb(n,i,MOD);
//				cout<<comb(n,i,MOD);
				res=res%MOD;	
			}
			
		}
		cout<<res;
	}
	
//	cout<<" "<<comb(2,1,MOD);
	
	return 0;
}