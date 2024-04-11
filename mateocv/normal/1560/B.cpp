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
		ll a,b,c; cin>>a>>b>>c;
		ll d=abs(a-b);
		if(max({a,b,c})>2*d){
			cout<<"-1\n";
		}else{
			if(c+d<=2*d){
				cout<<c+d<<"\n";
			}else{
				cout<<c-d<<"\n";
			}
		}
	}
	
	return 0;
}