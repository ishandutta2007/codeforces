#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

vector<ll> get(ll x){
	vector<ll> ans;
	ll now=2;
	while(x) ans.pb(x%now),x/=now,now++;
	sort(ALL(ans));
	return ans;
}

ll dp[21][21],am[21],acum[21];
vector<ll> ans;

ll solve(int pos, int rz){
	if(pos==SZ(ans)-1) return rz==0;
	ll &r=dp[pos][rz];
	if(r>=0)return r;
	r=0;
	
	//put zero
	if(rz) r=rz*solve(pos+1,rz-1);
	
	int did=pos;
	int amz=am[0]-rz;
	
	ll tot=acum[pos+1]-(did-amz);
	r+=tot*solve(pos+1,rz);
	return r;
	
}

ll f[21];

int main() {FIN;
	int tt; cin>>tt;
	while(tt--){
		f[0]=1; fore(i,1,21) f[i]=f[i-1]*i;

		ll x; cin>>x;
		ans=get(x);
		memset(am,0,sizeof(am));
		memset(dp,-1,sizeof(dp));
		for(auto x:ans) am[x]++;
		
		fore(i,1,21) acum[i]=acum[i-1]+am[i];
		
		ll r=solve(0,am[0]);
		fore(i,0,21) r/=f[am[i]];
		
		cout<<r-1<<"\n";
	}
}