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
		ll n,c0,c1,h; cin>>n>>c0>>c1>>h;
		ll res=0;
		string s; cin>>s;
		for(auto i:s){
			if(i=='0')res+=min(c0,c1+h);
			if(i=='1')res+=min(c1,c0+h);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}