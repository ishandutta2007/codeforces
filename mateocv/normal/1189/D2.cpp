#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[1005];
vector<pair<pair<ll,ll>,ll>> ed;

pair<ll,ll> find_leaf(ll u, ll v){
	ll vis[1005];
	mset(vis,0);
	pair<ll,ll> res={-1,-1};
	vis[v]=1;
	vis[u]=1;
	for(auto j:g[u]){
		if(!vis[j]){
			//cout<<j<<" ";
			queue<int> q;
			q.push(j);
			vis[j]=1;
			while(q.size()) {
				int t=q.front(); q.pop();
				if(SZ(g[t])==1){
					if(res.fst==-1){
						res.fst=t;
						//cout<<t<<" ";
						//q.clear();
						break;
					}else if(res.snd==-1&&res.fst!=t){
						res.snd=t;
						//cout<<"and "<<t<<"\n";
						//cout<<"\n";
						return res;
					}
				}
				for(int i:g[t]) {
					if(!vis[i]) {
						vis[i]=1;
						q.push(i);
					}
				}
			}
		}
	}
	
}

int main(){FIN;
	ll n; cin>>n;
	ll u,v,val;
	fore(i,0,n-1){
		cin>>u>>v>>val; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({{u,v},val});
	}
	fore(i,0,n){
		if(SZ(g[i])==2){
			cout<<"NO"; return 0;
		}
	}
	cout<<"YES\n";
	vector<pair<pair<ll,ll>,ll>> res;
	if(n==2){
		cout<<"1\n";
		cout<<ed[0].fst.fst+1<<" "<<ed[0].fst.snd+1<<" "<<ed[0].snd; return 0;
	}
	fore(i,0,n-1){
		if(SZ(g[ed[i].fst.fst])!=1&&SZ(g[ed[i].fst.snd])!=1){
			pair<ll,ll> a=find_leaf(ed[i].fst.fst,ed[i].fst.snd);
			pair<ll,ll> b=find_leaf(ed[i].fst.snd,ed[i].fst.fst);
			ll k=ed[i].snd/2;
			res.pb({{a.fst,b.fst},k});
			res.pb({{a.snd,b.snd},k});
			res.pb({{a.fst,a.snd},-k});
			res.pb({{b.fst,b.snd},-k});
		}else{
			if(SZ(g[ed[i].fst.fst])==1)swap(ed[i].fst.fst,ed[i].fst.snd);
			ll k=ed[i].snd/2;
			pair<ll,ll> a=find_leaf(ed[i].fst.fst,ed[i].fst.snd);
			res.pb({{a.fst,a.snd},-k});
			res.pb({{ed[i].fst.snd,a.fst},k});
			res.pb({{ed[i].fst.snd,a.snd},k});
		}
	}
	cout<<SZ(res)<<"\n";
	fore(i,0,SZ(res)){
		cout<<res[i].fst.fst+1<<" "<<res[i].fst.snd+1<<" "<<res[i].snd<<"\n";
	}
	return 0;
}