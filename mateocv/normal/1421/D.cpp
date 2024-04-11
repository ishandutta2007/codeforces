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

vector<pair<ll,ll>> v={{1,1},{0,1},{-1,0},{-1,-1},{0,-1},{1,0}};

ll INF=4e18;
ll x,y; 
ll c[6];

ll div(ll a, ll b, ll id){
	ll res=0;
	//cout<<a<<" "<<b<<" "<<id<<endl;
	if(v[id].fst!=0){
		res=a/v[id].fst;
	}else{
		res=b/v[id].snd;
	}
	if(res<0)return INF;
	if(v[id].fst*res==a&&v[id].snd*res==b)return res*c[id];
	return INF;
}

ll solve(ll ii, ll jj){
	vector<ll> val={abs(x),abs(y)};
	vector<ll> id={ii,jj};
	ll res=INF;
	for(auto i:val){
		for(auto j:id){
			res=min(res,div(x-i*v[j].fst,y-i*v[j].snd,ii+jj-j)+c[j]*i);
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>x>>y;
		fore(i,0,6)cin>>c[i];
		ll res=INF;
		if(x==0&&y==0){
			res=min(res,0ll);
		}
		fore(i,0,6){
			res=min(res,div(x,y,i));
		}
		fore(i,0,6){
			fore(j,i+1,6){
				res=min(res,solve(i,j));
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}