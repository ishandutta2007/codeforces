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

typedef ll tf;
typedef ll tc;
const tf INFFLOW=1e9;
const tf INFCOST=1e9;
struct MCF{
	int n;
	vector<tc> prio,pot; vector<tf> curflow; vector<int> prevedge,prevnode;
	priority_queue<pair<tc,int>,vector<pair<tc,int>>, greater<pair<tc,int>>> q;
	struct edge{int to,rev; tf f,cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s, int t, tf cap, tc cost){
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s, int t){
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0,s});
			fill(ALL(prio),INFCOST);
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()){
				auto cur=q.top();
				tc d=cur.fst;
				int u=cur.snd;
				q.pop();
				if(d!=prio[u])continue;
				fore(i,0,SZ(g[u])){
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f)continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio){
						prio[v]=nprio;
						q.push({nprio,v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u],e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST)break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t],INFFLOW-flow);
			flow+=df;
			for(int v=t;v!=s;v=prevnode[v]){
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};

int main(){FIN;
	int d,n; cin>>d>>n;
	vector<int> a(n);
	fore(i,0,n){
		string s; cin>>s;
		fore(j,0,d) a[i]=2*a[i]+(s[j]-'0');
	}
	
	MCF nt(2*n+2);
	int s=2*n,t=s+1;
	
	fore(i,0,n) nt.add_edge(s,i,1,0), nt.add_edge(n+i,t,1,0);
	
	fore(i,0,n) fore(j,0,n) if(i!=j && (a[i]&a[j])==a[i]){
		nt.add_edge(i,n+j,1,-(__builtin_popcount(a[i])+1));
	}
	
	auto res=nt.get_flow(s,t);
	
	vector<int> mt(n,-1),mt2(n,-1);
	
	fore(i,0,n) for(auto e : nt.g[i]){
		if(e.to>=n&&e.f>0) mt[i]=e.to-n, mt2[e.to-n]=i;
	}
	
	
	vector<vector<int>> v;
	fore(i,0,n) if(mt[i]<0){
		vector<int> now={i};
		int j=i;
		while(mt2[j]>=0) j=mt2[j],now.pb(j);
		reverse(ALL(now));
		v.pb(now);
	}
	
	string ans;
	fore(i,0,SZ(v)){
		int now=0;
		for(auto x:v[i]){
			fore(j,0,d) if((a[x]&(1<<j)) && !(now&(1<<j))){
				ans.pb(char(d-1-j+'0'));
			}
			now|=a[x];
		}

		if(i!=SZ(v)-1) ans.pb('R');
	}
	
	cout<<SZ(ans)<<"\n";
	for(auto x:ans)cout<<x<<" ";cout<<"\n";
}