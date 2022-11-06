#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y; cin>>n>>x>>y;
		string ss,se; cin>>ss>>se;
		vector<ll> v;
		fore(i,0,n){
			if(ss[i]!=se[i])v.pb(i);
		}
		if(SZ(v)&1){
			cout<<"-1\n";
			continue;
		}
		if(SZ(v)!=2){
			cout<<(SZ(v)/2)*y<<"\n";
		}else{
			if(v[0]+1==v[1])cout<<min(x,2ll*y)<<"\n";
			else cout<<y<<"\n";
		}
	}
	
	return 0;
}