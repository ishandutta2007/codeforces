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
		ll bas;
		fore(i,0,n)cin>>bas;
		vector<pair<ll,ll>> res;
		fore(i,0,n/2){
			fore(j,0,6)res.pb({2*i,2*i+1});
		}
		cout<<SZ(res)<<"\n";
		fore(i,0,SZ(res)){
			if(i&1)cout<<"1 ";
			else cout<<"2 ";
			cout<<res[i].fst+1<<" "<<res[i].snd+1<<"\n";
		}
	}
	
	return 0;
}