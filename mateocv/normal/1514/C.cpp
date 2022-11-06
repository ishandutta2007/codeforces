#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	vector<ll> res;
	fore(i,1,n){
		if(__gcd(i,n)==1)res.pb(i);
	}
	ll pr=1;
	for(auto i:res)pr=pr*i%n;
	if(pr==1){
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}else{
		cout<<SZ(res)-1<<"\n";
		for(auto i:res){
			if(i!=pr)cout<<i<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
}