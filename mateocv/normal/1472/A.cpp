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

ll dos(ll n){
	ll res=0;
	while(n%2==0){
		n/=2;
		res++;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll w,h,n; cin>>w>>h>>n;
		if(n<=(1ll<<dos(w))*(1ll<<dos(h))){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}