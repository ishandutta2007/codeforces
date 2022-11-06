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
		ll a,b; cin>>a>>b;
		if(b==0){
			cout<<fixed<<setprecision(12)<<1.<<"\n";
		}else if(a==0){
			cout<<fixed<<setprecision(12)<<0.5<<"\n";
		}else if(a>=4*b){
			cout<<fixed<<setprecision(12)<<(2.*b*a-2.*b*b)/(2.*a*b)<<"\n";
		}else{
			cout<<fixed<<setprecision(12)<<(2.*b*a-2.*b*b+((4.*b-a)*(4.*b-a))/8.)/(2.*a*b)<<"\n";
		}
	}
	
	return 0;
}