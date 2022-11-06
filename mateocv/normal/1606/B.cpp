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
		ll n,k; cin>>n>>k; n--;
		ll res=0;
		ll va=1;
		while(va<k&&n){
			n-=min(n,va);
			res++;
			va=min(2ll*va,k);
		}
		res+=(n+k-1)/k;
		cout<<res<<"\n";
	}
	
	return 0;
}