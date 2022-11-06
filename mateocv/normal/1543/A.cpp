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
		ll a,b; cin>>a>>b;
		if(a==b){
			cout<<"0 0\n";
		}else{
			ll d=abs(a-b);
			ll res=min(abs(a-(a/d)*d),abs(a-(a/d+1)*d));
			cout<<d<<" "<<res<<"\n";
		}
	}
	
	return 0;
}