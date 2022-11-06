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
		ll tot=0;
		fore(i,0,SZ(s))tot+=(s[i]==s[0]);
		if(tot==n){
			cout<<1+(n-1)/3<<"\n";
			continue;
		}
		vector<ll> v;
		ll van=0;
		char va='.';
		fore(i,0,SZ(s)){
			if(s[i]==va){
				van++;
			}else{
				if(van!=0)v.pb(van);
				va=s[i];
				van=1;
			}
		}
		if(s[0]==s.back()){
			v[0]+=van;
		}else{
			v.pb(van);
		}
		ll res=0;
		for(auto i:v)res+=i/3;
		cout<<res<<"\n";
	}
	
	return 0;
}