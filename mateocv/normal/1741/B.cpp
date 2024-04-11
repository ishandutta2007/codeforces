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
		if(n==3){
			cout<<"-1\n";
		}else if(n%2==0){
			fore(i,0,n)cout<<n-i<<" ";
			cout<<"\n";
		}else{
			vector<ll> res;
			while(n>=7){
				res.pb(n-1);
				res.pb(n);
				n-=2;
			}
			vector<ll> v={4,5,1,2,3};
			for(auto i:v)res.pb(i);
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}