#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll prim(string &s,char c){
	//ll res=SZ(s);
	fore(i,0,SZ(s)){
		if(s[i]==c){
			return i;
		}
	}
	return SZ(s);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll a=prim(s,'>');
		reverse(ALL(s));
		ll b=prim(s,'<');
		cout<<min(a,b)<<"\n";
	}
	
	return 0;
}