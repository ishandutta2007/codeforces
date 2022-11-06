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
		ll a,b,n; cin>>a>>b>>n;
		if(n%3==0){
			cout<<a<<"\n";
		}else if(n%3==1){
			cout<<b<<"\n";
		}else if(n%3==2){
			cout<<(a^b)<<"\n";
		}
	}
	
	return 0;
}