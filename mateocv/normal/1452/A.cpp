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
		ll x,y; cin>>x>>y;
		x=abs(x),y=abs(y);
		if(x==y){
			cout<<2*x<<"\n";
		}else{
			cout<<2*max(x,y)-1<<"\n";
		}
	}
	
	return 0;
}