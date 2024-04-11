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
		string s; cin>>s;
		vector<ll> v[2];
		fore(i,0,SZ(s)){
			v[(s[i]-'0')%2].pb(s[i]-'0');
		}
		ll l=0,r=0;
		while(l<SZ(v[0])||r<SZ(v[1])){
			if(l==SZ(v[0])){
				cout<<v[1][r]; r++;
			}else if(r==SZ(v[1])){
				cout<<v[0][l]; l++;
			}else{
				ll m=min(v[0][l],v[1][r]);
				cout<<m;
				if(m&1)r++;
				else l++;
			}
		}
		cout<<"\n";
	}
	
	return 0;
}