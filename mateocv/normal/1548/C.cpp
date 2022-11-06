#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MOD=1000000007;

const int MAXN=3000006;

ll fact[MAXN],facti[MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll sub(ll x, ll y){
	x-=y;
	if(x<0)x+=MOD;
	return x;
}

ll comb(ll n, ll k){
	if(k>n)return 0;
	ll res=fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
	//cout<<"comb "<<n<<" "<<k<<" "<<res<<"\n";
	return res;
}

ll res[3][MAXN];

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	facti[MAXN-1]=fpow(fact[MAXN-1],MOD-2);
	for(ll i=MAXN-2;i>=0;i--){
		facti[i]=facti[i+1]*(i+1)%MOD;
	}
	/*
	fore(i,0,5){
		cout<<fact[i]<<" "<<facti[i]<<"\n";
	}
	*/
	ll n,q; cin>>n>>q;
	fore(k,0,3){
		fore(i,1,n+1){
			res[k][MAXN-1]=add(res[k][MAXN-1],comb(3*i-k,MAXN-1));
		}
	}
	ll pr[3]={2,0,1};
	for(ll i=MAXN-2;i>=1;i--){
		fore(k,0,3){
			//cout<<k<<" "<<i<<":\n";
			res[k][i]=sub(res[pr[k]][i+1],res[k][i+1]);
			//cout<<res[k][i]<<" ";
			if(k==0)res[k][i]=add(res[k][i],comb(3*n+1,i+1));
			//cout<<res[k][i]<<" ";
			if(k==0)res[k][i]=sub(res[k][i],comb(1,i+1));
			//cout<<res[k][i]<<" ";
			//cout<<"\n";
		}
	}
	/*
	fore(i,1,3*n+1){
		fore(k,0,3){
			cout<<res[k][i]<<" ";
		}
		cout<<"\n";
	}
	*/
	while(q--){
		ll x; cin>>x;
		cout<<res[0][x]<<"\n";
	}
	
	return 0;
}