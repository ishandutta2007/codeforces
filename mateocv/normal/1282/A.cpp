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
		ll a,b,c,r; cin>>a>>b>>c>>r;
		ll s=c-r;
		if(s<min(a,b))s=min(a,b);
		if(s>max(a,b))s=max(a,b);
		ll e=c+r;
		if(e<min(a,b))e=min(a,b);
		if(e>max(a,b))e=max(a,b);
		cout<<abs(a-b)-(e-s)<<"\n";
	}
	
	return 0;
}