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

vector<ll> res;

void solve(ll n, ll k, ll st){
	//cout<<n<<" "<<k<<" "<<st<<endl;
	if(n==0)return;
	if(n==1)res.pb(st);
	else if(2<=n&&n<=62&&((1ll<<(n-2))&k)){
		ll lar=0;
		while(n-2-lar>=0&&((1ll<<(n-2-lar))&k))lar++;
		if(lar>0){
			fore(i,0,lar+1)res.pb(st+lar-i);
			solve(n-lar-1,k,st+lar+1);
		}else{
			res.pb(st);
			solve(n-1,k,st+1);
		}
	}else{
		res.pb(st);
		solve(n-1,k,st+1);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n, k; cin>>n>>k; k--;
		if(n<=61&&k>=(1ll<<(n-1))){
			cout<<"-1\n";
		}else{
			res.clear();
			solve(n,k,1);
			//reverse(ALL(res));
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}