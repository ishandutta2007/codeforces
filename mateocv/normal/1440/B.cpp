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
		ll n,k; cin>>n>>k;
		vector<ll> v(n*k);
		fore(i,0,n*k)cin>>v[i];
		sort(ALL(v));
		ll med=(n+1)/2-1;
		reverse(ALL(v));
		fore(i,0,med*k)v.pop_back();
		ll res=0;
		reverse(ALL(v));
		//for(auto i:v)cout<<i<<" "; cout<<"\n";
		fore(i,0,SZ(v)){
			if(i%(n-med)==0)res+=v[i];
		}
		cout<<res<<"\n";
	}
	
	return 0;
}