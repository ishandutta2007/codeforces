#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
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
		ll m=max(b+1-a,0ll);
		c-=m;
		a+=m;
		if(c<0){
			cout<<0<<"\n"; 
		}else if(c==0){
			cout<<1<<"\n";
		}else{
			ll mm=min(c,a-b-1);
			cout<<mm+(c-mm)/2+1<<"\n";
		}
	}
	
	return 0;
}