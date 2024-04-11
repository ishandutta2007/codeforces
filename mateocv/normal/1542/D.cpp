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

const ll MOD=998244353;

vector<ll> u;

ll dp[505][505][2];

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll f(ll x, ll y, ll z){
	ll &res=dp[x][y][z];
	if(res>=0)return res;
	if(x==SZ(u))return res=1;
	if(u[x]==1){
		res=add(f(x+1,y+1,z),f(x+1,y,z));
	}else if(u[x]==0){
		res=add(f(x+1,y,z),f(x+1,y,z));
	}else if(u[x]==-1){
		res=f(x+1,y,z);
		if(!z)res=add(res,f(x+1,max(y-1,0ll),z));
		else if(y)res=add(res,f(x+1,y-1,z));
	}else{
		res=f(x+1,y,1);
	}
	//cout<<x<<" "<<y<<" "<<z<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> v(n);
	fore(i,0,n){
		char ty; cin>>ty;
		if(ty=='+'){
			cin>>v[i];
		}else v[i]=0;
	}
	ll res=0;
	fore(i,0,n){
		if(v[i]){
			//cout<<i<<":\n";
			u.clear();
			fore(j,0,n){
				if(v[j]==0)u.pb(-1);
				else if(v[j]<v[i]||(v[j]==v[i]&&j<i))u.pb(1);
				else if(i!=j)u.pb(0);
				else u.pb(2);
			}
		}
		mset(dp,-1);
		res=(res+f(0,0,0)*v[i])%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}