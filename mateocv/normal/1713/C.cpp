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
		vector<ll> res(n);
		while(n>=2){
			ll s=sqrt(n-2); s++;
			fore(i,s*s-n+1,n)res[i]=s*s-i;
			n=s*s-n+1;
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}