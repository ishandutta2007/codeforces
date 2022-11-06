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

ll ask(vector<ll> v){
	cout<<"? ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll resp; cin>>resp;
	return resp;
}

const int MAXN=505;

ll n,k;

ll dp[MAXN];

ll INF=1e18;

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=INF;
	if(k<=x)res=min(res,f(x-k)+1);
	if(k+1<=x&&(k&1))res=min(res,f(x-k-1)+k+1);
	fore(i,1,k){
		if(k+1+i<=x&&(k&1))res=min(res,f(x-k-1-i)+k+2);
	}
	fore(i,1,k){
		if(k+i<=n&&2*i<=x)res=min(res,f(x-2*i)+2);
	}
	return res;
}

ll solve(ll ty, ll st, ll val){
	//cerr<<ty<<" "<<st<<" "<<val<<endl;
	ll res=0;
	if(ty==0){
		vector<ll> v;
		fore(i,0,k)v.pb(st+i);
		res=ask(v);
	}else if(ty==3){
		vector<ll> v[2];
		fore(i,0,val){
			v[0].pb((st+i)%n);
		}
		fore(i,0,val){
			v[1].pb((st+val+i)%n);
		}
		fore(i,0,k-val){
			v[0].pb((st+2*val+i)%n);
			v[1].pb((st+2*val+i)%n);
		}
		res=ask(v[0])^ask(v[1]);
	}else if(ty==1){
		fore(i,0,k+1){
			vector<ll> v;
			fore(j,0,k+1){
				if(i!=j)v.pb((st+j)%n);
			}
			res^=ask(v);
		}
	}else if(ty==2){
		ll tot=0;
		vector<ll> vv;
		fore(i,0,k+1){
			vector<ll> v;
			fore(j,0,k+1){
				if(i!=j)v.pb((st+j)%n);
			}
			vv.pb(ask(v));
			tot^=vv.back();
		}
		res=tot;
		vector<pair<ll,ll>> v;
		fore(i,0,k+1+val)v.pb({(st+i)%n,i});
		reverse(ALL(v));
		while(SZ(v)>k)v.pop_back();
		reverse(ALL(v));
		vector<ll> vm;
		for(auto i:v)vm.pb(i.fst);
		res^=ask(vm);
		for(auto i:v){
			if(i.snd<=k)res^=tot^vv[i.snd];
		}
	}
	return res;
}

int main(){FIN;
	cin>>n>>k;
	mset(dp,-1);
	ll resp=f(n);
	if(resp>INF/2){
		cout<<"-1\n";
		return 0;
	}
	ll res=0;
	ll x=n;
	while(x>0){
		ll br=0;
		if(k<=x&&resp==f(x-k)+1){
			res^=solve(0,x-k,0);
			x-=k;
			resp--;
			br++;
		}
		if(!br&&k+1<=x&&(k&1)&&resp==f(x-k-1)+k+1){
			res^=solve(1,x-k-1,0);
			x-=k+1;
			resp-=k+1;
			br++;
		}
		if(!br){
			fore(i,1,k){
				if(k+1+i<=x&&(k&1)&&resp==f(x-k-1-i)+k+2){
					res^=solve(2,x-k-1-i,i);
					x-=k+1+i;
					resp-=k+2;
					br++;
					break;
				}
			}
		}
		if(!br){
			fore(i,1,k){
				if(k+i<=n&&2*i<=x&&resp==f(x-2*i)+2){
					res^=solve(3,x-2*i,i);
					x-=2*i;
					resp-=2;
					br++;
					break;
				}
			}
		}
		if(!br){
			cout<<x<<endl;
			assert(0);
		}
		
	}
	cout<<"! "<<res<<"\n";
	return 0;
}