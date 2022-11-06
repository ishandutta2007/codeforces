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
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll> res;
		ll cant=0;
		for(auto i:s)cant+=(i=='0');
		fore(i,0,n){
			if(i<cant){
				if(s[i]=='1')res.pb(i);
			}else{
				if(s[i]=='0')res.pb(i);
			}
		}
		if(SZ(res)){
			cout<<"1\n"<<SZ(res)<<" ";
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}else{
			cout<<"0\n";
		}
	}
	
	return 0;
}