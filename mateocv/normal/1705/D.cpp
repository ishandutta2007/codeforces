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
	ll tt; cin>>tt;
	while(tt--){
		ll n; cin>>n;
		string s,t; cin>>s>>t;
		if(s[0]!=t[0]){
			cout<<"-1\n";
			continue;	
		}
		vector<ll> a,b;
		fore(i,1,n)if(s[i]!=s[i-1])a.pb(i);
		fore(i,1,n)if(t[i]!=t[i-1])b.pb(i);
		if(SZ(a)!=SZ(b)){
			cout<<"-1\n";
			continue;	
		}
		ll res=0;
		fore(i,0,SZ(a))res+=abs(a[i]-b[i]);
		cout<<res<<"\n";
	}
	
	return 0;
}