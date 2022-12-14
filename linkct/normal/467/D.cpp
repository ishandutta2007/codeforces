#include <cstring>
#include <iostream>
#include <string>
#include <map>
#define L 0
#define R 1
#define MAXN 200005
using namespace std;
typedef long long int ll;

struct edge{
	int n, p;
	void var(int _n, int _p){
		n = _n, p = _p;
	}
}edges[MAXN], edges_[MAXN];
bool vis[MAXN], ins[MAXN];
int n, m, g[MAXN], edgeSize, g_[MAXN], edgeSize_, cnt, nodes[MAXN][2];
int dp[MAXN][2];
int dfn[MAXN], low[MAXN], dfsClock, sccCnt, sccNo[MAXN], s[MAXN], top;
string essay[MAXN];
map <string, int> match;

inline int countR(string& x){
	int ret = 0;
	for(int i = 0; i < x.length(); ++ i)
		if(x[i] == 'r') ret ++;
	return ret;
}
inline bool betterThan(string& a, string& b){
	if(countR(a) != countR(b)) return countR(a) < countR(b);
	return a.length() < b.length();
}
inline char toLower(char x){
	if(x >= 'A' && x <= 'Z') return x - 'A' + 'a';
	return x;
}
int insertNode(string& x){
	if(match.find(x) == match.end()){
		match.insert(pair <string, int> (x, ++ cnt));
		nodes[cnt][L] = x.length();
		nodes[cnt][R] = countR(x);
		return cnt;
	}
	return match[x];
}
void addEdge(int a, int b){
	edges[++ edgeSize].var(b, g[a]);
	g[a] = edgeSize;
}
void addEdge_(int a, int b){
	//printf("added: %d %d\n", a, b);
	edges_[++ edgeSize_].var(b, g_[a]);
	g_[a] = edgeSize_;
}
void tarjan(int x){
	int p, v;
	low[x] = dfn[x] = ++ dfsClock;
	//printf("dfn: %d %d\n", x, dfsClock);
	s[++ top] = x;
	ins[x] = true;
	for(p = g[x]; p; p = edges[p].p){
		v = edges[p].n;
		if(!dfn[v]){
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}else if(ins[v])
			low[x] = min(low[x], dfn[v]);
	}
	if(low[x] == dfn[x]){
		//printf("%d\n", x);
		sccCnt ++;
		while(top && s[top] != x){
			sccNo[s[top --]] = sccCnt;
			ins[s[top + 1]] = false;
		}
		ins[s[top --]] = false;
		sccNo[x] = sccCnt;
	}
	//printf("low: %d %d\n", x, low[x]);
}
void dfs(int x){
	if(vis[x]) return;
	int v, p;
	vis[x] = true;
	for(p = g_[x]; p; p = edges_[p].p){
		v = edges_[p].n;
		dfs(v);
		if(dp[x][R] > dp[v][R] || (dp[x][R] == dp[v][R] && dp[x][L] > dp[v][L]))
			dp[x][L] = dp[v][L], dp[x][R] = dp[v][R];
	}
}
int main(){
	int i, j, p;
	ll ansLen = 0, ansR = 0;
	string temp1, temp2;
	ios_base :: sync_with_stdio(false);
	cin >> m;
	for(i = 1; i <= m; ++ i){
		cin >> essay[i];
		for(j = 0; j < essay[i].length(); ++ j)
			essay[i][j] = toLower(essay[i][j]);
		insertNode(essay[i]);
	}
	cin >> n;
	for(i = 1; i <= n; ++ i){
		cin >> temp1 >> temp2;
		for(j = 0; j < temp1.length(); ++ j)
			temp1[j] = toLower(temp1[j]);
		for(j = 0; j < temp2.length(); ++ j)
			temp2[j] = toLower(temp2[j]);
		addEdge(insertNode(temp1), insertNode(temp2));
	}
	memset(dp, 0x3f, sizeof(dp));
	for(i = 1; i <= cnt; ++ i)
		if(!dfn[i]) tarjan(i);
	for(i = 1; i <= cnt; ++ i){
		if(nodes[i][R] < dp[sccNo[i]][R] || (nodes[i][R] == dp[sccNo[i]][R] && nodes[i][L] < dp[sccNo[i]][L]))
			dp[sccNo[i]][L] = nodes[i][L], dp[sccNo[i]][R] = nodes[i][R];
		for(p = g[i]; p; p = edges[p].p)
			if(sccNo[i] != sccNo[edges[p].n])
				addEdge_(sccNo[i], sccNo[edges[p].n]);
	}
	for(i = 1; i <= sccCnt; ++ i)
		if(!vis[i]) dfs(i);
	for(i = 1; i <= m; ++ i)
		ansLen += dp[sccNo[match[essay[i]]]][L], ansR += dp[sccNo[match[essay[i]]]][R];
	cout << ansR << ' ' << ansLen << endl;
	return 0;
}