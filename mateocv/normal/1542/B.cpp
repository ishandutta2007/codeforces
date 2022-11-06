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
		ll n,a,b; cin>>n>>a>>b;
		ll res=0,va=1;
		if(a==1){
			res=((n-va)%b==0);
		}else{
			while(va<=n){
				if((n-va)%b==0)res=1;
				va*=a;
			}
		}
		if(res)cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}