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
		ll n,m; cin>>n>>m;
		string s; cin>>s;
		vector<ll> sump={0};
		for(auto i:s)sump.pb(sump.back()+(i=='1'));
		vector<ll> res(n*m);
		fore(i,0,m*n){
			if(i-m>=0)res[i]+=res[i-m];
			res[i]+=(!!(sump[i+1]-sump[max(i+1-m,0ll)]));
		}
		vector<ll> c(m);
		ll totc=0;
		fore(i,0,n*m){
			if(s[i]=='1'){
				if(!c[i%m]){
					totc++;
					c[i%m]++;
				}
			}
			res[i]+=totc;
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}