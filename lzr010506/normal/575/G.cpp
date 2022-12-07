#include <map>
#include <iostream>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <cstdio>  
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <stdio.h>
#include <ctime>  

using namespace std;
template <class T>
inline bool rd(T &ret) {
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
template <class T>
inline void pt(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) pt(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 1e8;
const int N = 1e5 + 10;
int n, m;
vector<pii> G[N];
int d2[N];
int inq[N];
void spfa(int x, int *dis){
	memset(inq, 0, sizeof inq);
	queue<int>q;
	q.push(x);
	for (int i = 0; i < n; i++)dis[i] = inf;
	dis[x] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop(); inq[u] = 0;
		for (auto v : G[u]){
			if (dis[v.first] > dis[u] + 1){
				dis[v.first] = dis[u] + 1;
				if (!inq[v.first])inq[v.first] = 1, q.push(v.first);
			}
		}
	}
}
int pre[N], val[N];
int dis[N];
struct Node{
	int val, c, dep;
	bool operator<(const Node&a)const{
		return val < a.val;
	}
};
int mdis;
int vis[N];
stack<Node>que;
int tim;
void go(queue<Node>&D){
	tim++;
	set<int>ch;
	while (!D.empty()){
		auto u = D.front(); D.pop();
		for (auto v : G[u.c]){
			if (dis[v.first] != u.dep - 1)continue;
			if (vis[v.first] == 0 || (vis[v.first] == tim && val[v.first] > v.second))
			{
				vis[v.first] = tim;
				val[v.first] = v.second;
				pre[v.first] = u.c;
				ch.insert(v.first);
			}
		}
	}
	set<pii>CH;
	for (auto v : ch)CH.insert({ val[v], v });
	for (auto v = CH.rbegin(); v != CH.rend(); v++)
		que.push({ v->first, v->second, dis[v->second] });
}
void bfs(){
	while (!que.empty())que.pop();
	for (int i = 0; i < n; i++)
	{
		if (vis[i] && dis[i] == mdis)
			que.push({ 0, i, mdis });
	}
	memset(vis, 0, sizeof vis);
	while (!que.empty()){
		queue<Node>D;
		D.push(que.top());
		que.pop();
		while (!que.empty()){
			if (D.front().dep == que.top().dep && D.front().val == que.top().val)
			{
				D.push(que.top());
				que.pop();
			}
			else break;
		}
		go(D);
	}
}
vector<int>ans;
void spfa2(){
	memset(inq, 0, sizeof inq);
	memset(vis, 0, sizeof vis);
	memset(pre, -1, sizeof pre);
	queue<int>q;
	q.push(n - 1);
	mdis = dis[n - 1];
	vis[n - 1] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (auto v : G[u]){
			if (v.second || vis[v.first])continue;
			vis[v.first] = 1;
			q.push(v.first);
			pre[v.first] = u;
			mdis = min(mdis, dis[v.first]);
		}
	}
}
void work(int idx){
	memset(pre, -1, sizeof pre);
	memset(vis, 0, sizeof vis);
	queue<int>q[2];
	int cur = 0, old = 1;
	q[0].push(0);
	for (int i = 0; i <= idx; i++)
	{
		swap(cur, old);
		while (!q[old].empty()){
			int u = q[old].front(); q[old].pop(); vis[u] = 1;
			for (auto v : G[u])
			{
				if (dis[u] + 1 == dis[v.first] && v.second == ans[i])
				{
					q[cur].push(v.first);
					pre[v.first] = u;
				}
			}
		}
	}
	while (!q[cur].empty())
	{
		int u = q[cur].front(); q[cur].pop();
		if (u == n - 1)break;
		for (auto v : G[u]){
			if (vis[v.first] || pre[v.first] != -1 || v.second)continue;
			vis[v.first] = 1;
			if (v.second == 0)
			{
				q[cur].push(v.first);
				pre[v.first] = u;
			}
		}
	}
}
int main(){
	rd(n); rd(m);
	for (int i = 1, u, v, V; i <= m; i++){
		rd(u); rd(v); rd(V);
		G[u].push_back({ v, V });
		G[v].push_back({ u, V });
	}
	spfa(0, dis);
	spfa2();
	bfs();
	int u = 0;
	while (1){
		ans.push_back(val[u]);
		if (u == n - 1)break;
		u = pre[u];
	}
	int id = ans.size() - 1;
	while (id)
	if (ans[id])break;
	else id--;
	work(id);
	for (; id >= 0; id--)pt(ans[id]);	puts("");
	ans.clear();
	int U = n - 1;
	while (1){
		ans.push_back(U);
		if (U == 0)break;
		U = pre[U];
	}
	reverse(ans.begin(), ans.end());
	pt(int(ans.size())); puts("");
	for (auto v : ans)pt(v), putchar(' ');
	return 0;
}