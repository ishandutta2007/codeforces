#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#define MN 1010000

typedef long long ll;
typedef std::pair<int, int> P;
typedef std::pair<P, int> PP;
std::set<int> st;
ll c[MN], Ans[MN];
std::vector<PP> q1[MN];
std::vector<P> q2[MN];
std::vector<int> e1[MN], e2[MN], t1[MN], t2[MN];
int tot1, tot2, tot = 0;
int id1[MN], id2[MN], siz[MN];
bool ok1[MN], ok2[MN];
int n, m; 

void add(int x, int v) {for(int i = x; i <= m; i += i & -i) c[i] += v;}
ll query(int x) {ll ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

void dfs1(int x)
{
	for(int i = 0; i < t1[x].size(); i++) add(t1[x][i], siz[x]);
	for(int i = 0; i < q1[x].size(); i++) Ans[q1[x][i].second] = query(q1[x][i].first.first) - query(q1[x][i].first.second);
	for(int i = 0; i < e1[x].size(); i++) dfs1(e1[x][i]);
	for(int i = 0; i < t1[x].size(); i++) add(t1[x][i], -siz[x]);
}

void dfs2(int x)
{
	for(int i = 0; i < t2[x].size(); i++) st.insert(t2[x][i]);
	for(int i = 0; i < q2[x].size(); i++) q1[x].push_back(PP(P(q2[x][i].first, *(--st.upper_bound(q2[x][i].first))), q2[x][i].second));
	for(int i = 0; i < e2[x].size(); i++) dfs2(e2[x][i]);
	for(int i = 0; i < t2[x].size(); i++) st.erase(t2[x][i]);	
}

int main()
{
	st.insert(0);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) id1[i] = id2[i] = i, siz[i] = 1;
	tot1 = tot2 = n;
	for(int i = 1; i <= m; i++)
	{
		char s[2]; int a, b; scanf("%s%d", s, &a);
		if(s[0] == 'U') 
		{
			scanf("%d", &b);
			tot1++;
			e1[tot1].push_back(id1[a]);
			e1[tot1].push_back(id1[b]); 
			siz[tot1] = siz[id1[a]] + siz[id1[b]]; id1[a] = tot1; ok1[b] = 1;
		}
		if(s[0] == 'M')
		{
			scanf("%d", &b);
			tot2++;
			e2[tot2].push_back(id2[a]);
			e2[tot2].push_back(id2[b]);
			id2[a] = tot2; ok2[b] = 1;
		}
		if(s[0] == 'A') t1[id1[a]].push_back(i);
		if(s[0] == 'Z') t2[id2[a]].push_back(i);
		if(s[0] == 'Q') q2[a].push_back(P(i, ++tot));
	}
	++tot1; ++tot2;
	for(int i = 1; i <= n; i++)
	{
		if(!ok1[i]) e1[tot1].push_back(id1[i]);
		if(!ok2[i]) e2[tot2].push_back(id2[i]);
	}
	dfs2(tot2); dfs1(tot1); 
	for(int i = 1; i <= tot; i++) printf("%lld\n", Ans[i]);
}