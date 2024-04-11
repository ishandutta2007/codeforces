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
		cout<<max(0ll,max(b,c)+1-a)<<" ";
		cout<<max(0ll,max(a,c)+1-b)<<" ";
		cout<<max(0ll,max(a,b)+1-c)<<" ";
		cout<<"\n";
	}
	
	return 0;
}