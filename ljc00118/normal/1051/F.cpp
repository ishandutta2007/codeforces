#include <bits/stdc++.h>
#define X first
#define Y second
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 1e5 + 25;

bool used[N];
int x[25], y[25], z[25], dis[N];
int f[N], pre[N][18], sum[N][18], dep[N], id[N], h[N * 3], sta[N], use[N], Us, USS[N];
int n, m, q, len, dfn, MX, top;

vector < pair <int, int> > G[N], G2[N];

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}

void init(int u, int fa) {
    pre[u][0] = fa; dep[u] = dep[fa] + 1; id[u] = ++dfn;
    for(int i = 1; i <= 17; i++) pre[u][i] = pre[pre[u][i - 1]][i - 1], sum[u][i] = sum[u][i - 1] + sum[pre[u][i - 1]][i - 1];
    for(vector < pair <int, int> > :: iterator it = G2[u].begin(); it != G2[u].end(); it++)
        if(it -> X != fa) sum[it -> X][0] = it -> Y, init(it -> X, u);
}

int LCA(int x, int y) {
    MX = 0;
    if(dep[x] > dep[y]) swap(x, y);
    for(int i = 17; i >= 0; i--)
        if(dep[pre[y][i]] >= dep[x])
            MX += sum[y][i], y = pre[y][i];
    if(x == y) return x;
    for(int i = 17; i >= 0; i--)
        if(pre[x][i] != pre[y][i])
            MX += (sum[x][i] + sum[y][i]), x = pre[x][i], y = pre[y][i];
    MX += (sum[x][0], sum[y][0]);
    return pre[x][0];
}

bool cmp(int x, int y) {return id[x] < id[y];}

#undef int
int main() {
#define int long long
	memset(dis, 0x3f, sizeof(dis));
	cin >> n >> m;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		read(a); read(b); read(c);
		int l = find(a), r = find(b);
		if(l == r) {
			len++;
			x[len] = a, y[len] = b, z[len] = c;
		} else {
			f[l] = r;
			G2[a].push_back( make_pair(b, c) );
			G2[b].push_back( make_pair(a, c) );
		}
	}
	init(1, 0);
	cin >> q;
	while(q--) {
		int s, t, k = len * 2;
		read(s); read(t);
		for(int j = 1; j <= len; j++) h[j * 2 - 1] = x[j], h[j * 2] = y[j];
		h[++k] = s, h[++k] = t;
		sort(h + 1, h + k + 1, cmp);
		k = unique(h + 1, h + k + 1) - h - 1;
//		for(int i =1; i <= k; i++) {
//			fprintf(stderr, "h[%d] = %d\n", i, h[i]);
//		} 
		sta[top = 1] = 1; G[1].clear();
		for(int i = 1; i <= k; i++) {
            if(h[i] == 1) continue;
            int lca = LCA(h[i], sta[top]);
            if(lca != sta[top]) {
                while(id[lca] < id[sta[top - 1]]) {
                    LCA(sta[top - 1], sta[top]);
                    G[sta[top - 1]].push_back( make_pair(sta[top], MX) );
                    G[sta[top]].push_back( make_pair(sta[top - 1], MX) );
                    top--;
                }
                if(id[lca] > id[sta[top - 1]]) {
                    LCA(lca, sta[top]);
                    G[lca].clear();
                    G[lca].push_back( make_pair(sta[top], MX) );
                    G[sta[top]].push_back( make_pair(lca, MX) );
                    sta[top] = lca;
                } else LCA(lca, sta[top]), G[lca].push_back( make_pair(sta[top], MX) ), G[sta[top]].push_back( make_pair(lca, MX) ), top--;
            }
            G[h[i]].clear(); sta[++top] = h[i];
        }
        for(int i = 1; i < top; i++) LCA(sta[i], sta[i + 1]), G[sta[i]].push_back( make_pair(sta[i + 1], MX) ), G[sta[i + 1]].push_back( make_pair(sta[i], MX) );
        for(int i = 1; i <= len; i++) G[x[i]].push_back( make_pair(y[i], z[i]) ), G[y[i]].push_back( make_pair(x[i], z[i]) );
       	queue <int> q; q.push(s); dis[s] = 0; used[s]; Us = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop(); if(!USS[u]) {USS[u] = 1; use[++Us] = u;}
			for(vector < pair <int, int> > :: iterator it = G[u].begin(); it != G[u].end(); it++) {
				if(dis[it -> first] > dis[u] + it -> second) {
					dis[it -> first] = dis[u] + it -> second;
					if(!used[it -> first]) {
						used[it -> first] = 1;
						q.push(it -> first);
					}
				}
			}
			used[u] = 0;
		}
		printf("%I64d\n", dis[t]);
		for(int i = 1; i <= Us; i++) {
			dis[use[i]] = dis[0];
			used[use[i]] = 0;
			USS[use[i]] = 0;
		}
	}
	return 0;
}