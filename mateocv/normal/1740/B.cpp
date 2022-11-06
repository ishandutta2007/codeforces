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
		vector<pair<ll,ll>> a(n);
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			if(a[i].snd<a[i].fst)swap(a[i].fst,a[i].snd);
		}		
		ll res=0,maxi=0;
		for(auto i:a)res+=i.fst,maxi=max(maxi,i.snd);
		res+=maxi;
		cout<<2ll*res<<"\n";
	}
	
	return 0;
}