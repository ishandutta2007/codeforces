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

ll solve(ll a, ll b, ll c, ll d){
	if(a-c*b>0)return -1;
	ll l=a/(b*d),r=(a+b*d-1)/(b*d)+1;
	__int128 res=a;
	fore(i,l,r+1){
		if(0<=i&&i<=c/d){
			__int128 va=1;
			va*=i+1;
			va*=i;
			va*=d;
			va*=b;
			va/=2;
			res=max(res,(i+1)*a-va);
		}
	}
	assert(res==(ll)res);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		cout<<solve(a,b,c,d)<<"\n";
	}
	
	return 0;
}