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
		vector<string> res(n);
		fore(i,0,n){
			fore(j,0,n)res[i].pb('=');
		}
		fore(i,0,n)res[i][i]='X';
		vector<ll> v;
		fore(i,0,n){
			if(s[i]=='2')v.pb(i);
		}
		if(SZ(v)&&SZ(v)<3){
			cout<<"NO\n";
		}else{
			fore(i,0,SZ(v)){
				res[v[i]][v[(i+1)%SZ(v)]]='+';
				res[v[(i+1)%SZ(v)]][v[i]]='-';
			}
			cout<<"YES\n";
			fore(i,0,n)cout<<res[i]<<"\n";
		}
	}
	
	return 0;
}