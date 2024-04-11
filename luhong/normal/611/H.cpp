#include <cstdio>
#include <cstring>
#include <iostream> 
#include <set>
#define MN 201000

int h[50], nxt[300], to[300], cap[300], K = 1;
int iter[50], lvl[50], q[50], hh = 0, tt = 0;
int cnt[7][7], sum[7];
int b[7], d[7], id[7], now[7]; 
int x[MN], y[MN];
int n, k;
std::set<int> st;

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cap[K] = c;}
void insw(int u, int v, int c) {ins(u, v, c); ins(v, u, 0);}

bool bfs(int S, int T)
{
	memset(lvl, 0, sizeof(lvl));
	lvl[S] = 1;
	hh = 0; tt = 0; q[tt++] = S;
	while(hh < tt)
	{
		int u = q[hh++]; iter[u] = h[u];
		for(int i = h[u]; i; i = nxt[i])
		{
			if(cap[i ^ 1] && !lvl[to[i]])
			{
				lvl[to[i]] = lvl[u] + 1;
				q[tt++] = to[i];
			}
		}
	}
	if(!lvl[T]) return 0;
	return 1;
}

int dfs(int u, int T, int f)
{
	if(u == T) return f;
	int used = 0;
	for(int &i = iter[u]; i; i = nxt[i])
	{
		if(cap[i] && lvl[to[i]] == lvl[u] - 1)
		{
			int w = dfs(to[i], T, std::min(cap[i], f - used));
			if(w)
			{
				cap[i] -= w; cap[i ^ 1] += w; used += w; 
				if(used == f) return f;
			}
		}
	}
	return used;
}

bool build()
{
	memset(h, 0, sizeof(h)); K = 1;
	int S = 28, T = 29, tot = 0;
	for(int i = 1; i <= 6; i++)
		for(int j = i; j <= 6; j++)
		{
			++tot;
			if(cnt[i][j] < 0) return 0;
			insw(S, tot, cnt[i][j]);
			insw(tot, 21 + i, (int)1e9);
			insw(tot, 21 + j, (int)1e9); 
		}
	for(int i = 1; i <= 6; i++) insw(21 + i, T, sum[i] - 1);
	return 1;
}

void prufer(int n)
{
	memset(d, 0, sizeof(d));
	st.clear();
	for(int i = 1; i <= n - 1; i++) 
		cnt[x[i]][y[i]]++;
		
	for(int i = 1; i <= n; i++) st.insert(i);
	for(int i = 1; i <= n - 2; i++) if(++d[b[i]] == 1) st.erase(b[i]);
	for(int i = 1; i <= n - 2; i++)
	{
		x[i] = *st.begin(); y[i] = b[i];
		st.erase(st.begin());
		if(--d[b[i]] == 0) st.insert(b[i]);
	}
	x[n - 1] = *st.begin(); y[n - 1] = *st.rbegin();
	for(int i = 1; i <= n - 1; i++) 
	{
		if(x[i] > y[i]) std::swap(x[i], y[i]);
		cnt[x[i]][y[i]]--;
	}
}

bool check()
{
	if(k > 1) prufer(k);
	if(!build()) return 0;
	int flow = 0;
	int S = 28, T = 29;
	while(bfs(T, S))
	{
		int f;
		do {
			f = dfs(S, T, 1e9);
			flow += f;
		} while(f);
	}
	if(flow < n - k) return 0;
	int tot = k - 1, w = 0;
	for(int i = 1; i <= tot; i++) x[i] = id[x[i]], y[i] = id[y[i]];
	
	for(int i = 1; i <= 6; i++)
		for(int j = i; j <= 6; j++)
		{
			++w;
			for(int o = h[w]; o; o = nxt[o])
			{
				if(to[o] == S) continue;
				if(to[o] == 21 + i)
				{
					for(int p = 1; p <= cap[o ^ 1]; p++)
					{
						++tot; x[tot] = now[i]++; y[tot] = id[j];
					}
				}
				else
				{
					for(int p = 1; p <= cap[o ^ 1]; p++)
					{
						++tot; x[tot] = now[j]++; y[tot] = id[i];
					}
				}
			}
		}
	return 1;
}

bool flag = 0; 
void brute(int x)
{
	if(flag) return;
	if(x > k - 2)
	{
		flag |= check();
		return; 
	}
	for(int i = 1; i <= k; i++) {b[x] = i; brute(x + 1);}
}

int digit(int x)
{
	int p = 0;
	while(x) {p++; x /= 10;}
	return p;
}

int main()
{
	id[1] = 1; for(int i = 2; i <= 6; i++) id[i] = id[i - 1] * 10;
	for(int i = 1; i <= 6; i++) now[i] = id[i] + 1;
	scanf("%d", &n); k = digit(n);
	for(int i = 1; i < n; i++)
	{
		char s[8], t[8];
		scanf("%s%s", s, t);
		cnt[std::min(strlen(s), strlen(t))][std::max(strlen(s), strlen(t))]++;
	}
	for(int i = 1; i <= n; i++) sum[digit(i)]++;
	brute(1);
	if(!flag) puts("-1");
	else for(int i = 1; i < n; i++) printf("%d %d\n", x[i], y[i]);
}