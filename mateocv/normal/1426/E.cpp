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

typedef ll tf;
typedef ll tc;
const tf INFFLOW=1e9+10;
const tc INFCOST=1e9+10;
struct MCF{
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge,prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s, int t, tf cap, tc cost) {
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s, int t) {
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0, s});
			fill(ALL(prio),INFCOST); 
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()) {
				auto cur=q.top();
				tc d=cur.fst;
				int u=cur.snd;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0; i<SZ(g[u]); ++i) {
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio) {
						prio[v]=nprio;
						q.push({nprio, v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t], INFFLOW-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};

MCF mini(8),maxi(8);

int main(){FIN;
	ll n; cin>>n;
	ll a[3],b[3];
	fore(i,0,3)cin>>a[i];
	fore(i,0,3)cin>>b[i];
	fore(i,0,3){
		mini.add_edge(0,i+1,a[i],0);
		mini.add_edge(i+4,7,b[i],0);
		maxi.add_edge(0,i+1,a[i],0);
		maxi.add_edge(i+4,7,b[i],0);
	}
	fore(i,0,3){
		fore(j,0,3){
			if(i==(j+2)%3){
				mini.add_edge(i+1,j+4,n,1);
				maxi.add_edge(i+1,j+4,n,-1);
			}else{
				mini.add_edge(i+1,j+4,n,0);
				maxi.add_edge(i+1,j+4,n,0);
			}
		}
	}
	cout<<mini.get_flow(0,7).snd<<" "<<-maxi.get_flow(0,7).snd;
	return 0;
}