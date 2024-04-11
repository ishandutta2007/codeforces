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
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		fore(i,0,n){
			vector<ll> v;
			fore(j,0,n){
				if(i==j||s[j][i]=='1')v.pb(j);
			}
			cout<<SZ(v)<<" ";
			for(auto i:v)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}