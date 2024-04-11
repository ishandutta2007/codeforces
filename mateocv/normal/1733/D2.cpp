#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=5050;

vector<ll> v;

ll INF=1e18;

ll dp[MAXN][MAXN];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(v))return res=(y?INF:0);
	res=f(x+1,y);
	if(x+1<SZ(v)&&y)res=min(res,abs(v[x]-v[x+1])+f(x+2,y-1));
	//cout<<x<<" "<<y<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y; cin>>n>>x>>y;
		string ss,se; cin>>ss>>se;
		v.clear();
		fore(i,0,n){
			if(ss[i]!=se[i])v.pb(i);
		}
		if(SZ(v)&1){
			cout<<"-1\n";
			continue;
		}
		if(x>=y){
			if(SZ(v)!=2){
				cout<<(SZ(v)/2)*y<<"\n";
			}else{
				if(v[0]+1==v[1])cout<<min(x,2ll*y)<<"\n";
				else cout<<y<<"\n";
			}
		}else{
			fore(i,0,SZ(v)+1){
				fore(j,0,SZ(v)+1){
					dp[i][j]=-1;
				}
			}
			ll res=INF;
			fore(i,0,SZ(v)/2+1){
				res=min(res,(SZ(v)/2-i)*y+f(0,i)*x);
			}
			cout<<res<<"\n";
		}
	}
	
	return 0;
}