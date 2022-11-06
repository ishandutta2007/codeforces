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
		ll n=SZ(s);
		vector<ll> sump[2]={{0},{0}};
		fore(k,0,2){
			for(auto i:s){
				sump[k].pb(sump[k].back()+(i=='0'+k));
			}
		}
		ll res=0;
		fore(i,0,n){
			if(sump[0][i]-sump[0][0]==0&&sump[1][n]-sump[1][i+1]==0)res++;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}