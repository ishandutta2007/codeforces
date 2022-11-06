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

char c[110][110];

vector<vector<pair<ll,ll>>> res;

vector<pair<ll,ll>> typ(ll a, ll b, ll ty){
	vector<pair<ll,ll>> res;
	if(ty!=0)res.pb({a,b});
	if(ty!=1)res.pb({a,b+1});
	if(ty!=2)res.pb({a+1,b});
	if(ty!=3)res.pb({a+1,b+1});
	return res;
}

void ap(vector<pair<ll,ll>> v){
	for(auto i:v)c[i.fst][i.snd]=c[i.fst][i.snd]^'0'^'1';
}

void solve(ll a, ll b){
	//cout<<a<<" "<<b<<"\n";
	ll tot=0;
	pair<ll,ll> pos={-1,-1};
	fore(i,0,2){
		fore(j,0,2){
			tot+=(c[a+i][b+j]-'0');
			if(c[a+i][b+j]=='1'){
				pos={a+i,b+j};
			}
		}
	}
	//cout<<tot<<"\n";
	if(tot==0)return;
	if(tot==1){
		fore(i,0,2){
			fore(j,0,2){
				if(pos!=pair<ll,ll>({a+i,b+j})){
					auto vv=typ(a,b,2*i+j);
					ap(vv);
					res.pb(vv);
				}
			}
		}
		return;
	}
	if(tot==2){
		auto vv=typ(a,b,0);
		ap(vv);
		res.pb(vv);
		solve(a,b);
		return;
	}
	if(tot==3){
		fore(i,0,2){
			fore(j,0,2){
				if(c[a+i][b+j]=='0'){
					auto vv=typ(a,b,2*i+j);
					ap(vv);
					res.pb(vv);
					return;
				}
			}
		}
		return;
	}
	if(tot==4){
		fore(i,0,2){
			fore(j,0,2){
				auto vv=typ(a,b,2*i+j);
				ap(vv);
				res.pb(vv);
			}
		}
		return;
	}
}

void print(ll n, ll m){
	fore(i,0,n){
		fore(j,0,m){
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		res.clear();
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			fore(j,0,m){
				cin>>c[i][j];
			}
		}
		fore(i,0,n/2){
			fore(j,0,m/2){
				solve(2*i,2*j);
			}
		}
		//print(n,m);
		if(n&1){
			fore(j,0,m/2){
				solve(2*(n/2)-1,2*j);
			}
		}
		//print(n,m);
		if(m&1){
			fore(i,0,n/2){
				solve(2*i,2*(m/2)-1);
			}
		}
		//print(n,m);
		if((m&1)&&(n&1)){
			solve(2*(n/2)-1,2*(m/2)-1);
		}
		//print(n,m);
		cout<<SZ(res)<<"\n";
		for(auto i:res){
			for(auto j:i)cout<<j.fst+1<<" "<<j.snd+1<<" ";
			cout<<"\n";
		}
		//print(n,m);
	}
	
	return 0;
}