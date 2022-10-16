/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=1000000;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
struct edge {
    int to, capacity, cost, rev;
    edge() {}
    edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
const int maxn=666;
struct Min_Cost_Max_Flow {
    int V, H[maxn + 5], dis[maxn + 5], PreV[maxn + 5], PreE[maxn + 5];
    vector<edge> G[maxn + 5];
    void Init(int n) {
        V = n;
        for (int i = 0; i <= V; ++i)G[i].clear();
    }
    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back(edge(to, cap, cost, G[to].size()));
        G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
    }
    int Min_cost_max_flow(int s, int t, int f, int& flow) {
        int res = 0; fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
            fill(dis, dis + 1 + V, 0x3f3f3f3f);
            dis[s] = 0; q.push(pair<int, int>(0, s));
            while (!q.empty()) {
                pair<int, int> now = q.top(); q.pop();
                int v = now.second;
                if (dis[v] < now.first)continue;
                for (int i = 0; i < G[v].size(); ++i) {
                    edge& e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        PreV[e.to] = v;
                        PreE[e.to] = i;
                        q.push(pair<int, int>(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == 0x3f3f3f3f)break;
            for (int i = 0; i <= V; ++i)H[i] += dis[i];
            int d = f;
            for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d; flow += d; res += d*H[t];
            for (int v = t; v != s; v = PreV[v]) {
                edge& e = G[PreV[v]][PreE[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }
        }
        return res;
    }
    int Max_cost_max_flow(int s, int t, int f, int& flow) {
        int res = 0;
        fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue <pair<int, int>> q;
            fill(dis, dis + 1 + V, -inf);
            dis[s] = 0;
            q.push(pair<int, int>(0, s));
            while (!q.empty()) {
                pair<int, int> now = q.top(); q.pop();
                int v = now.second;
                if (dis[v] > now.first)continue;
                for (int i = 0; i < G[v].size(); ++i) {
                    edge& e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] < dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        PreV[e.to] = v;
                        PreE[e.to] = i;
                        q.push(pair<int, int>(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == -inf)break;
            for (int i = 0; i <= V; ++i)H[i] += dis[i];
            int d = f;
            for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
            f -= d; flow += d;
            res += d*H[t];
            for (int v = t; v != s; v = PreV[v]) {
                edge& e = G[PreV[v]][PreE[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }
        }
        return res;
    }
}G;
int n1,n2,m,r,b;
char c1[233],c2[233];
int x[233],y[233];
int main(){
	G.Init(660);
	cin>>n1>>n2>>m>>r>>b;
	cin>>(c1+1)>>(c2+1);
	const int S=404,T=405;
	for(int i=1;i<=n1;i++){
		if(c1[i]=='R')G.add_edge(S,i,1,-inf);
		else G.add_edge(i,T,inf,0);
		if(c1[i]=='B')G.add_edge(i,T,1,-inf);
		else G.add_edge(S,i,inf,0);
	}
	for(int i=1;i<=n2;i++){
		if(c2[i]=='B')G.add_edge(S,i+n1,1,-inf);
		else G.add_edge(i+n1,T,inf,0);
		if(c2[i]=='R')G.add_edge(i+n1,T,1,-inf);
		else G.add_edge(S,i+n1,inf,0);
	}
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];y[i]+=n1;
		G.add_edge(x[i],y[i],1,r);
		G.add_edge(y[i],x[i],1,b);
	}
	G.add_edge(S,T,inf,0);
	int flow=0;
	int cost=G.Min_cost_max_flow(S,T,inf,flow);
	cerr<<flow<<" "<<cost<<endl;
	for(int i=1;i<=n1;i++)if(c1[i]!='U')cost+=inf;
	for(int i=1;i<=n2;i++)if(c2[i]!='U')cost+=inf;
	if(cost>=inf){
		puts("-1");return 0;
	}
	cout<<cost<<endl;
	for(int p=1;p<=m;p++){
		char ans='U';
		for(int i=0;i<666;i++){
			for(auto &e:G.G[i]){
				if(e.cost>0&&i==x[p]&&e.to==y[p]){
					if(e.capacity<G.G[e.to][e.rev].capacity){ans='R';e.to=-1;break;}
				}
				if(e.cost>0&&i==y[p]&&e.to==x[p]){
					if(e.capacity<G.G[e.to][e.rev].capacity){ans='B';e.to=-1;break;}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}