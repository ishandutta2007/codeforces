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
		ll aa,bb,n; cin>>aa>>bb>>n;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll maxi=0;
		fore(i,0,n)maxi=max(maxi,a[i]);
		ll tot=0;
		fore(i,0,n){
			tot+=((b[i]+aa-1)/aa)*a[i];
		}
		if(tot<bb+maxi)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}