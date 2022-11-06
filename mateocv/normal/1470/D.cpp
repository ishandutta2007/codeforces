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

const int MAXN=300005;

vector<ll> g[MAXN];

ll c[MAXN];

queue<ll> q;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear();
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		q.push(0);
		fore(i,0,n)c[i]=-1;
		while(SZ(q)){
			//cout<<"Loopeando"<<endl;
			auto b=q.front();
			q.pop();
			if(c[b]==-1){
				c[b]=1;
				for(auto i:g[b]){
					if(c[i]==-1){
						c[i]=0;
						for(auto j:g[i]){
							if(c[j]==-1)q.push(j);
						}
					}
				}
			}
		}
		vector<ll> res;
		ll br=0;
		fore(i,0,n){
			if(c[i]==-1){
				br++; break;
			}
			if(c[i])res.pb(i);
		}
		if(br)cout<<"NO\n";
		else{
			cout<<"YES\n";
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}