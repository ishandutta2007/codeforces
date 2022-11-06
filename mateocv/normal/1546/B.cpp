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
		vector<vector<ll>> res(m,vector<ll>(26));
		fore(i,0,n){
			string s; cin>>s;
			fore(j,0,m){
				res[j][s[j]-'a']++;
			}
		}
		fore(i,0,n-1){
			string s; cin>>s;
			fore(j,0,m){
				res[j][s[j]-'a']--;
			}
		}
		fore(i,0,m){
			fore(j,0,26){
				if(res[i][j])cout<<char('a'+j);
			}
		}
		cout<<"\n";
	}
	
	return 0;
}