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

vector<short> ca[(1ll<<23)];

ll cant[(1ll<<23)];

ll resa[(1ll<<23)];

const ll MOD=998244353;

int main(){FIN;
	ll n; cin>>n;
	vector<short> c[n];
	fore(i,0,n){
		c[i].resize(26);
		string s; cin>>s;
		for(auto j:s)c[i][j-'a']++;
	}
	fore(i,0,(1ll<<n))ca[i].resize(26);
	fore(i,1,(1ll<<n)){
		if(__builtin_popcount(i)==1){
			ca[i]=c[31-__builtin_clz(i)];
			continue;
		}
		ll b=31-__builtin_clz(i);
		ca[i]=ca[i^(1ll<<b)];
		fore(j,0,26){
			ca[i][j]=min(ca[i][j],c[b][j]);
		}
	}
	fore(i,1,(1ll<<n)){
		cant[i]=1;
		fore(j,0,26)cant[i]=cant[i]*(ca[i][j]+1)%MOD;
		//cout<<i<<" "<<cant[i]<<"\n";
	}
	fore(i,1,(1ll<<n)){
		resa[i]=((__builtin_popcount(i)&1)?1:-1)*cant[i];
	}
	fore(j,0,n){
		fore(i,1,(1ll<<n)){
			if(i&(1ll<<j)){
				resa[i]=resa[i]+resa[i^(1ll<<j)];
			}
		}
	}
	fore(i,1,(1ll<<n)){
		resa[i]=resa[i]%MOD;
		while(resa[i]<0)resa[i]+=MOD;
	}
	ll res=0;
	fore(i,0,(1ll<<n)){
		//cout<<i<<" "<<resa[i]<<"\n";
		auto p=__builtin_popcount(i);
		ll s=0;
		fore(j,0,n){
			if((1ll<<j)&i)s+=j+1;
		}
		res^=p*s*resa[i];
	}
	cout<<res<<"\n";
	
	return 0;
}