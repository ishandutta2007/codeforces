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

ll sumd(ll n){
	ll res=0;
	while(n>0){
		res+=n%10;
		n/=10;
	}
	return res;
}

ll pot[19];

int main(){FIN;
	ll t; cin>>t;
	pot[0]=1;
	fore(i,1,19)pot[i]=pot[i-1]*10;
	while(t--){
		ll n,s; cin>>n>>s;
		ll res=2e18;
		fore(i,0,19){
			ll m=((n+pot[i]-1)/pot[i])*pot[i];
			if(sumd(m)<=s){
				res=min(res,m-n);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}