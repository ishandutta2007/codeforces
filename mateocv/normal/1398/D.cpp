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

ll dp[202][202][202];

ll n[3];
vector<ll> v[3];

ll f(ll x, ll y, ll z){
	ll &r=dp[x][y][z];
	if(r>=0)return r;
	r=0;
	if(x<n[0]&&y<n[1]){
		r=max(r,v[0][x]*v[1][y]+f(x+1,y+1,z));
	}
	if(x<n[0]&&z<n[2]){
		r=max(r,v[0][x]*v[2][z]+f(x+1,y,z+1));
	}
	if(y<n[1]&&z<n[2]){
		r=max(r,v[1][y]*v[2][z]+f(x,y+1,z+1));
	}
	return r;
}

int main(){FIN;
	fore(k,0,3)cin>>n[k];
	fore(k,0,3){
		fore(i,0,n[k]){
			ll lle; cin>>lle;
			v[k].pb(lle);
		}
		sort(ALL(v[k]));
		reverse(ALL(v[k]));
	}
	mset(dp,-1);
	cout<<f(0,0,0);
	
	return 0;
}