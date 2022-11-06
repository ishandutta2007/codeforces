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

ll solve(ll n, ll k, ll l, ll r, ll lll, ll rr){
	//cout<<n<<endl;
	ll inter=max(min(r,rr)-max(l,lll),0ll);
	if(inter>0){
		ll tot=inter*n;
		if(tot>=k){
			return 0;
		}else{
			ll maxi=max(r,rr)-min(l,lll)-inter;
			if(k-tot<=maxi*n)return k-tot;
			else return maxi*n+2ll*(k-tot-maxi*n);
		}
	}else{
		if(k==0)return 0;
		ll d=max(l,lll)-min(r,rr);
		ll maxi=r+rr-l-lll+d;
		if(k<=maxi)return d+k;
		else{
			if(n>1)return min(d+maxi+solve(n-1,k-maxi,l,r,lll,rr),d+maxi+2ll*(k-maxi));
			else return d+maxi+2ll*(k-maxi);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k,l,r,lll,rr; cin>>n>>k>>l>>r>>lll>>rr;
		cout<<solve(n,k,l,r,lll,rr)<<"\n";
	}
	
	return 0;
}