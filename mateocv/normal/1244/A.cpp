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
		ll a,b,c,d,k; cin>>a>>b>>c>>d>>k;
		if((a+c-1)/c+(b+d-1)/d>k){
			cout<<-1<<"\n";
		}else{
			cout<<(a+c-1)/c<<" "<<(b+d-1)/d<<"\n";
		}
	}
	
	return 0;
}