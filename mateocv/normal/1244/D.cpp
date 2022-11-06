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

vector<ll> g[100005];

ll c[100005][3];
ll dp[100005][3];
vector<ll> v;

/*ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(x==0){
		r=c[v[0]][y]; return r;
	}
	r=min({f(x-1,(y+1)%3)+c[v[x]][y],f(x-1,(y+2)%3)+c[v[x]][y]});
	return r;
}*/

int main(){FIN;
	ll n; cin>>n;
	fore(k,0,3){
		fore(i,0,n)cin>>c[i][k];
	}
	ll u,vv;
	fore(i,0,n-1){
		cin>>u>>vv; u--; vv--;
		g[u].pb(vv);
		g[vv].pb(u);
	}
	ll s=-1;
	fore(i,0,n){
		if(SZ(g[i])>=3){
			cout<<-1; return 0;
		}else if(SZ(g[i])==1)s=i;
	}
	v.pb(s);
	s=g[s][0];
	while(SZ(v)<n-1){
		if(g[s][0]==v.back()){
			v.pb(s);
			s=g[s][1];
		}else{
			v.pb(s);
			s=g[s][0];
		}
	}
	v.pb(s);
	//fore(i,0,n)cout<<v[i]<<" "; cout<<"\n";
	/*mset(dp,-1);
	ll resp=min({f(n-1,0),f(n-1,1),f(n-1,2)});
	cout<<resp<<"\n";
	ll res[n];
	fore(i,0,n){
		fore(k,0,3){
			if(f(n-1-i,k)==resp){
				res[v[n-1-i]]=k;
				resp-=c[v[n-1-i]][k];
				break;
			}
		}
	}
	fore(i,0,n)cout<<res[i]+1<<" ";*/
	ll resp[6];
	mset(resp,0);
	fore(k,0,6){
		if(k<3){
			fore(i,0,n){
				resp[k]+=c[v[i]][(i+k)%3];
			}
		}else{
			fore(i,0,n){
				resp[k]+=c[v[i]][(2*i+k)%3];
			}
		}
	}
	ll res[n];
	cout<<min({resp[0],resp[1],resp[2],resp[3],resp[4],resp[5]})<<"\n";
	fore(k,0,6){
		if(resp[k]==min({resp[0],resp[1],resp[2],resp[3],resp[4],resp[5]})){
			if(k<3){
				fore(i,0,n){
					res[v[i]]=(i+k)%3;	
				}
				break;
			}else{
				fore(i,0,n){
					res[v[i]]=(2*i+k)%3;	
				}
				break;
			}
		}
	}
	fore(i,0,n)cout<<res[i]+1<<" ";
	return 0;
}