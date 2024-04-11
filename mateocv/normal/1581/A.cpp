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

const int MOD=1000000007;

ll fact[200005];

int main(){FIN;
	fact[0]=1;
	fore(i,1,200005)fact[i]=fact[i-1]*i%MOD;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<fact[2*n-1]*n%MOD<<"\n";
	}
	
	return 0;
}