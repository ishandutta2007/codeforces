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

bool eq(string s){
	if(!SZ(s))return 0;
	fore(i,0,SZ(s)){
		if(s[i]!=s[0])return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		string va;
		ll res=1;
		fore(i,0,n){
			if(s[i]=='W'){
				res=(res&&!eq(va));
				va="";
			}else{
				va+=s[i];
			}
		}
		res=(res&&!eq(va));
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}