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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,n; cin>>a>>b>>c>>n;
		ll m=max({a,b,c});
		if((a+b+c+n)%3==0&&3*m-a-b-c<=n){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}