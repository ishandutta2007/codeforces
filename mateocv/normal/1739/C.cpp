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

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll res[62][3];

ll comb[62][62];

int main(){FIN;
	fore(i,0,62){
		fore(j,0,i+1){
			if(j==0||j==i)comb[i][j]=1;
			else comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
		}
	}
	res[0][2]=1;
	for(ll i=2;i<=60;i+=2){
		res[i][0]=res[i-2][1];
		res[i][1]=res[i-2][0];
		res[i][2]=res[i-2][2];
		ll tot=comb[i][i/2];
		ll te=tot*fpow(2,MOD-2)%MOD;
		res[i][0]=(res[i][0]+te)%MOD;
		te=te*(i/2-1)%MOD;
		te=te*fpow(i-1,MOD-2)%MOD;
		res[i][1]=(res[i][1]+te)%MOD;
	}
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		fore(k,0,3)cout<<res[x][k]<<" ";
		cout<<"\n";
	}
	
	return 0;
}