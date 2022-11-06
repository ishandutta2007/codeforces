#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[100005];
ll c[100005];
ll vis[100005];
//ll dp[100005];
ll r=-1;
pair<ll,ll> res[100005];

void bfs(ll x) {
	queue<int>q;
	vis[x]=1;
	q.push(x);
	while(q.size()) {
		int t=q.front(); q.pop();
		//cout<<t+1<<" ";
		for(int i:g[t]) {
			if(!vis[i]) {
				res[t].fst+=c[i];
				vis[i]=1;
				q.push(i);
			}
		}
	}
}

int main(){FIN;
	ll n; cin>>n;
	mset(vis,0);
	//mset(res,0);
	//mset(dp,-1);
	ll a,b;
	fore(i,0,n){
		cin>>a>>b; a--;
		if(a==-2){
			r=i;
			c[i]=b;
		}else{
			g[a].pb(i);
			c[i]=b;	
		}
		
	}
	
	fore(i,0,n){
		res[i].snd=i;
		res[i].fst=c[i];
	}
	bfs(r);
	//fore(i,0,n)cout<<res[i].snd<<" ";
	fore(i,0,n){
		if(res[i].fst==SZ(g[i])+1){
			res[i].fst=0;
		}else{
			res[i].fst=1;
		}
	}
	
	sort(res,res+n);
	fore(i,0,n){
		if(!res[i].fst){
			cout<<res[i].snd+1<<" ";
		}else{
			break;
		}
	}
	if(res[0].fst){cout<<-1;
	}
	
	return 0;
}