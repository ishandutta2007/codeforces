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

const ll maxi=(1ll<<20);

ll comb(ll n, ll k){
	return (n&k)==k;
}

ll val[22][2];

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,1,21){
		fore(j,0,2){
			val[i][j]=0;
			ll disp=n-1-(i-1)-2+j;
			fore(ii,k-2+j,disp+1)val[i][j]^=comb(disp,ii);
			//cout<<i<<" "<<j<<" "<<val[i][j]<<"\n";
		}
	}
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	bitset<maxi+10>res;
	fore(i,0,n){
		ll p=a[i];
		fore(j,0,20){
			if(p>=maxi)break;
			if(val[j+1][i==0||i+j==n-1]||(i==0&&j==n-1&&k==0))res[p]=(res[p]^1);
			if(i+j+1>=n)break;
			p=p*(1ll<<min(a[i+j+1],21ll));
		}
	}
	ll ya=0;
	for(ll i=maxi-1;i>=0;i--){
		if(res[i])ya=1;
		if(ya)cout<<res[i];
	}
	if(!ya)cout<<"0";
	cout<<"\n";
	
	return 0;
}