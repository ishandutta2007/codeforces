#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=1e5+10;
ll INF=1e18,ds[MAXN][2];
vector<pair<ll,int>> g[MAXN],rev[MAXN];

int main(){FIN;
	int n,m; cin>>n>>m;
	fore(i,0,m){
		int x,y,w; cin>>x>>y>>w;
		x--; y--;
		g[x].pb({y,w});
		rev[y].pb({x,w});
	}
	
	fore(i,0,n) fore(j,0,2) ds[i][j]=INF;
	
	priority_queue<pair<ll,ii>, vector<pair<ll,ii>>, greater<pair<ll,ii>>> q;
	q.push({0,{0,0}});
	ds[0][0]=0;
	
	while(SZ(q)){
		ll d=q.top().fst;
		int pos=q.top().snd.fst;
		int wh=q.top().snd.snd;
		q.pop();
		
		if(d!=ds[pos][wh])continue;
		
		if(wh==0){
			for(auto x:g[pos]) if(d+x.snd<ds[x.fst][0]){
				ds[x.fst][0]=d+x.snd;
				q.push({ds[x.fst][0], {x.fst,0}});
			}
			
			if(d<ds[pos][1]){
				ds[pos][1]=d;
				q.push({ds[pos][1],{pos,1}});
			}
		}
		
		else{
			for(auto x:rev[pos]) if(d+x.snd<ds[x.fst][1]){
				ds[x.fst][1]=d+x.snd;
				q.push({ds[x.fst][1], {x.fst,1}});
			}
		}
	}
	
	fore(i,1,n){
		ll x=min(ds[i][0],ds[i][1]);
		if(x==INF)x=-1;
		cout<<x<<" ";
	}
	cout<<"\n";
	
	
}