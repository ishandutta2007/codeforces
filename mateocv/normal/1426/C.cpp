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
		ll n; cin>>n;
		ll s=sqrt(n);
		if(s*s>=n){
			cout<<2*s-2<<"\n";
		}else if(s*(s+1)>=n){
			cout<<2*s-1<<"\n";
		}else if((s+1)*(s+1)>=n){
			cout<<2*s<<"\n";
		}else assert(0);
	}
	
	return 0;
}