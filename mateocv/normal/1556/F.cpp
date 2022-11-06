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

const ll MOD=1000000007;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

const int MAXN=15;

ll p[MAXN][MAXN];

ll pg[MAXN][1<<MAXN];

bool cmp(ll a, ll b){
	return __builtin_popcountll(a)<__builtin_popcountll(b);
}

ll n;

ll calc(ll x, ll y){
	ll res=1;
	fore(i,0,n){
		if((1ll<<i)&x)res=res*pg[i][y]%MOD;
	}
	return res;
}

ll sub(ll x, ll y){
	x-=y;
	if(x<0)x+=MOD;
	return x;
}

int main(){FIN;
	cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		fore(j,0,n){
			p[i][j]=a[i]*fpow(a[i]+a[j],MOD-2)%MOD;
			//cout<<i<<" "<<j<<" "<<p[i][j]<<"\n";
		}
	}
	fore(i,0,n){
		fore(j,0,(1ll<<n)){
			if(j&(1ll<<i))continue;
			pg[i][j]=1;
			fore(jj,0,n){
				if((1ll<<jj)&j)pg[i][j]=pg[i][j]*p[i][jj]%MOD;
			}
			//cout<<i<<" "<<j<<" "<<pg[i][j]<<"\n";
		}
	}
	vector<ll> v;
	fore(i,1,(1ll<<n))v.pb(i);
	sort(ALL(v),cmp);
	//for(auto i:v)cout<<i<<" ";
	//cout<<"\n";
	vector<ll> pc(1ll<<n);
	ll res=0;
	for(auto i:v){
		ll pr=1;
		for(ll j=(i-1)&i;j;j=(j-1)&i){
			pr=sub(pr,calc(j,i^j)*pc[j]%MOD);
		}
		pc[i]=pr;
		pr=pr*calc(i,((1ll<<n)-1)^i)%MOD;
		res=(res+__builtin_popcount(i)*pr)%MOD;
		//cout<<i<<" "<<pr<<"\n";
	}
	cout<<res<<"\n";
	
	return 0;
}