#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

const int MAXN=5015;
const ll INF=1e9;
int n,m,dist[MAXN][MAXN];
bool vis[MAXN];
vector<int>g[MAXN];
vector<ii>st[MAXN];

int get(int fr,ll cnt,ll budget) {
	memset(vis,0,sizeof(vis));
	priority_queue<ii,vector<ii>>pq;
	queue<ii>q;
	q.push({fr,0});
	vis[fr]=1;
	ll cost=0,cur=0;
	while(SZ(q)) {
		ii t=q.front();q.pop();
		
		for(auto it:st[t.fst]) {
			pq.push(it);
			cur+=it.snd;
			cost+=it.fst*it.snd;
		}
		
		while(cur>cnt) {
			ii bad=pq.top();pq.pop();
			cur-=bad.snd;
			cost-=bad.fst*bad.snd;
			if(cur<cnt) {
				cost+=bad.fst*(cnt-cur);
				pq.push({bad.fst,cnt-cur});
				cur=cnt;
			}
		}
		
		if(cur==cnt && cost<=budget)return t.snd;
		for(int i:g[t.fst]) {
			if(vis[i])continue;
			vis[i]=1;
			q.push({i,t.snd+1});
		}
	}
	return -1;
}


int main() {FIN;
	cin>>n>>m;
	fore(i,0,m) {
		int x,y;cin>>x>>y;x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int w;cin>>w;
	fore(i,0,w) {
		int c,k,p;cin>>c>>k>>p;c--;
		st[c].pb({p,k});
	}
	int q;cin>>q;
	while(q--) {
		ll g,rr,a;cin>>g>>rr>>a;g--;
		cout<<get(g,rr,a)<<"\n";
	}
}