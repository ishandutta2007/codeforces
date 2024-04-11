#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

ll l[200010],t[200010];
const int MX=200010;

int main() {FIN;
	ll n,r,ans=0; cin>>n>>r;
	fore(i,0,n) cin>>l[i];
	fore(i,0,n) cin>>t[i];
	fore(i,0,n) if(t[i]<l[i]) cout << "-1\n",exit(0);
	ll rem=0,tim=0;
	vector<ll> res;
	fore(i,0,n){
		if(rem>=l[i]){	//comi con el poder
			rem-=l[i];
			tim+=l[i];
			continue;
		}
		l[i]-=rem;
		t[i]-=rem;
		tim+=rem;
		ll must=max(0ll,2*l[i]-t[i]);
		ll reps = (must+r-1)/r;
		ll fir=tim+2ll*(l[i]-must);
		tim=fir;
		
		fore(i,0,reps){
			if(SZ(res)==MX) break;
			res.pb(fir); fir+=r;
		}
		
		
		tim+=must;
		ans+=reps;
		
		
		rem=r*reps-must;
	}
	assert(ans>=0);
	cout << ans << "\n";
	if(SZ(res)<=1e5){
		for(auto x:res) cout << x << " "; cout << "\n";
	}
}