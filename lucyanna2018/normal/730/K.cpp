#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define maxN 2111111
#define maxM 2111111

int n, m, S, T;
vector<pair<int, int> > e[maxN], e1[maxN];
bool visd[maxN];
int x[maxM], y[maxM], dir[maxM];
int p[maxN], dep[maxN], pe_id[maxN], son[maxN], in_cnt[maxN], out_cnt[maxN];
int q[maxN*2];

bool paint(int e_id, int f) {
	if(dir[e_id]!=-1) return false;
	dir[e_id] = f;
	if(f != (dep[x[e_id]] < dep[y[e_id]])) {
		in_cnt[y[e_id]]++;
		out_cnt[x[e_id]]++;
	} else {
		in_cnt[x[e_id]]++;
		out_cnt[y[e_id]]++;
	}
	return true;
}

void dfs(int cur, int par) {
	p[cur] = par;
	visd[cur] = true;
	for(int i=0;i<e[cur].size();i++) {
		int nxt = e[cur][i].first, id = e[cur][i].second;
		if (nxt==par) continue;
		if (visd[nxt] && dep[nxt] < dep[cur]) {
			// B1
			int v = son[nxt];
			//printf("- %d %d\n", cur, nxt);
			e1[cur].push_back(make_pair(v, id));
			e1[v].push_back(make_pair(cur, id));
			continue;
		}
		if (visd[nxt]) continue;
		pe_id[nxt] = id; //nxtTid
		son[cur] = nxt;
		dep[nxt] = dep[cur] + 1;
		dfs(nxt, cur); 
	}
}

int main() {
	int CASE;
	for(scanf("%d", &CASE); CASE--;) {
		scanf("%d%d%d%d", &n, &m, &S, &T);
		for(int i=1;i<=n;i++) {
			e[i].clear();
			e1[i].clear();
		}
		for(int i=0;i<m;i++) {
			scanf("%d%d", &x[i], &y[i]);
			e[x[i]].push_back(make_pair(y[i], i));
			e[y[i]].push_back(make_pair(x[i], i));
		}
		dep[S] = 0;
		memset(visd, false, (n+1)*sizeof(int));
		pe_id[S] = -1;
		dfs(S, -1);
		
		memset(visd, false, (n+1)*sizeof(int));
		memset(in_cnt, 0, (n+1)*sizeof(int));
		memset(out_cnt, 0, (n+1)*sizeof(int));
		memset(dir, -1, m*sizeof(int));
		int l=0, r=0;
		q[r++] = T; q[r++] = 0; // 0: low -> high; 1: high -> low
		visd[T] = true;
		while(l<r) {
			int cur = q[l++], f = q[l++];
			while(pe_id[cur]>=0 && paint(pe_id[cur], f)) {
				for(int i=0;i<e1[cur].size();i++) {
					int nxt = e1[cur][i].first, id = e1[cur][i].second;
					if (paint(id, f) && !visd[nxt]) { //B
						q[r++] = nxt;
						q[r++] = 1-f;
						visd[nxt] = true;
					}
				}
				cur = p[cur];
			}
		}
		
		bool sol = true;
		for(int i=0;i<m && sol;i++)
			if (dir[i]==-1) sol = false;
		for(int i=1;i<=n && sol;i++) {
			if(i==S && (out_cnt[i]==0 || in_cnt[i]>0)) sol = false;
			if(i==T && (in_cnt[i]==0 || out_cnt[i]>0)) sol = false;
			if(i!=S && i!=T && (!in_cnt[i] || !out_cnt[i])) sol = false;
		}
		if (!sol) printf("No\n");
		else {
			printf("Yes\n");
			for(int i=0;i<m;i++) {
				if (dir[i] == (dep[x[i]] < dep[y[i]])) swap(x[i], y[i]);
				printf("%d %d\n", x[i], y[i]);
			}
		}
	}
	
	return 0;
}