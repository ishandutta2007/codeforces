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
 
vector<ll> solve(ll n){
	//cout<<"ESTOY "<<n<<" ";
	if(n==1)return {1};
	ll l=-1;
	fore(i,0,40){
		if((1ll<<i)-1>=n){
			l=i;
			break;
		}
	}
	//if(rand()%50==0)exit(0);
	//cout<<l<<endl;
	if(3*(1ll<<(l-2))<=n){
		auto res=solve((1ll<<(l-1))-1);
		res.pb(n-((1ll<<(l-1))-1));
		return res;
	}else{
		auto res=solve(n-(1ll<<(l-2)));
		res.pb((1ll<<(l-2)));
		return res;
	}
}
 
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		auto res=solve(n);
		//for(auto i:res)cout<<i<<" "; cout<<"\n";
		cout<<SZ(res)-1<<"\n";
		fore(i,0,SZ(res)-1)cout<<res[i+1]-res[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}