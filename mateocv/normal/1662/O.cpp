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

ll bo[42][720];

void circ(ll r, ll a, ll b){
	if(b<a)b+=360;
	fore(i,2*a,2*b+1){
		bo[2*r][i%720]=1;
	}
}

void line(ll r0, ll r1, ll a){
	fore(i,2*r0,2*r1+1){
		bo[i][2*a]=1;
	}
}

vector<pair<ll,ll>> dir={{0,1},{1,0},{0,-1},{-1,0}};

bool valid(ll x){
	return 0<=x&&x<42;
}

ll vis[42][720];

void dfs(ll x, ll y){
	vis[x][y]=1;
	for(auto ii:dir){
		auto nx=x+ii.fst,ny=(y+ii.snd+720)%720;
		if(valid(nx)&&bo[nx][ny]==0&&!vis[nx][ny]){
			dfs(nx,ny);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,42){
			fore(j,0,720){
				bo[i][j]=0;
				vis[i][j]=0;
			}
		}
		fore(i,0,n){
			char ty; cin>>ty;
			ll a,b,c; cin>>a>>b>>c;
			if(ty=='C')circ(a,b,c);
			if(ty=='S')line(a,b,c);
		}
		dfs(0,0);
		if(vis[41][0])cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}