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

ll sig(ll n){
	if(n>0)return 1;
	if(n<0)return -1;
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll u=0;
		ll maxi=0;
		ll res=0;
		fore(i,0,n){
			if(sig(a[i])==sig(u)){
				maxi=max(maxi,a[i]);
			}else{
				res+=maxi;
				u=a[i];
				maxi=a[i];
			}
		}
		res+=maxi;
		cout<<res<<"\n";
	}
	
	return 0;
}