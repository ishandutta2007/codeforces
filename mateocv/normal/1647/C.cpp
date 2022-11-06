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
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		if(s[0][0]=='1'){
			cout<<"-1\n";
			continue;
		}
		vector<vector<ll>> res;
		for(ll i=n-1;i>=0;i--){
			for(ll j=m-1;j>=0;j--){
				if(s[i][j]=='1'){
					if(i)res.pb({i-1,j,i,j});
					else res.pb({i,j-1,i,j});
				}
			}
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res){
			for(auto j:i)cout<<j+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}