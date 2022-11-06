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

const ll MOD=998244353;

ll n,m,k,p; 

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

const int MAXK=2020;

ll stn[MAXK][MAXK];

int main(){FIN;
	fore(i,0,MAXK){
		fore(j,0,MAXK){
			if(i==0&&j==0)stn[i][j]=1;
			else if(i==0||j==0)stn[i][j]=0;
			else stn[i][j]=(stn[i-1][j]*j+stn[i-1][j-1])%MOD;
			//if(max(i,j)<6)cout<<i<<" "<<j<<" "<<": "<<stn[i][j]<<"\n";
		}
	}
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		p=((m+1)/2)*fpow(m,MOD-2)%MOD;
		ll res=0,prod=1,po=1;
		fore(i,0,k+1){
			ll te=stn[k][i];
			te=te*prod%MOD;
			te=te*po%MOD;
			res=(res+te)%MOD;
			po=po*p%MOD;
			prod=prod*(n-i)%MOD;
		}
		res=res*fpow(m,n)%MOD;
		cout<<res<<"\n";
	}
	
	return 0;
}