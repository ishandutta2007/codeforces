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
const int inf=0x3f3f3f3f;
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
string t;
int n;
string s[105];
struct edge {
    int to, capacity, cost, rev;
    edge() {}
    edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
const int maxn=3333;
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
    int Min_cost_flow(int s, int t, int f, int& flow) {
        int res = 0; fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
            fill(dis, dis + 1 + V, inf);
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
            if (dis[t] == inf)break;
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
}G;
int a[105],b[105],cnt[105][26],f[105][26],c[105],d[105],tot,S,T;
int main(){
	cin>>t;cin>>n;S=++tot;T=++tot;
	for(int i=0;i<t.size();i++)d[i]=++tot;
	G.Init(tot+n*30);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		a[i]=++tot;b[i]=++tot;
		G.add_edge(S,a[i],inf,0);
		G.add_edge(a[i],b[i],c[i],i);
		for(char c:s[i])cnt[i][c-'a']++;
		for(int j=0;j<26;j++)f[i][j]=++tot,G.add_edge(b[i],f[i][j],cnt[i][j],0);
		for(char c:s[i]){
			for(int j=0;j<t.size();j++)if(t[j]==c){
				G.add_edge(f[i][c-'a'],d[j],1,0);
			}
		}
	}
	for(int i=0;i<t.size();i++)G.add_edge(d[i],T,1,0);
	int tmp=0;
	int ans=G.Min_cost_flow(S,T,inf,tmp);
	if(tmp<t.size()){
		puts("-1");
	}else{
		cout<<ans<<endl;
	}
	return 0;
}