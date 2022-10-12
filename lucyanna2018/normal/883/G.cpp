#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;

#define ran 303333

int n, m, st, eid, cnt;
vector<int> e1[ran];
vector<pair<int, int> > e2[ran];
bool v[ran];
int dir[ran];

void o() {
	printf("%d\n", cnt);
	for(int i=1;i<=eid;i++) printf("%c", dir[i] ? '+' : '-');
	puts("");
}

void dfs_ma(int cur) {
	v[cur] = true; cnt++;
	for(int i=0;i<e1[cur].size();i++) {
		int nxt = e1[cur][i];
		if (!v[nxt]) dfs_ma(nxt);
	}
	for(int i=0;i<e2[cur].size();i++) {
		int nxt = e2[cur][i].first;
		int id = e2[cur][i].second;
//		printf("- %d %d %d\n", cur, nxt, id);
		if (!v[nxt]) {
			dir[labs(id)] = (id>0) ? 1 : 0;
			dfs_ma(nxt);
		}
	}
}

void dfs_mi(int cur) {
	v[cur] = true; cnt++;
	for(int i=0;i<e1[cur].size();i++) {
		int nxt = e1[cur][i];
		if (!v[nxt]) dfs_mi(nxt);
	}
	for(int i=0;i<e2[cur].size();i++) {
		int id = e2[cur][i].second;
		dir[labs(id)] = (id>0) ? 0 : 1;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &st);
	eid = 1;
	for(int i=0;i<m;i++) {
		int x, y, z; scanf("%d%d%d", &z, &x, &y);
		if (z==1) e1[x].push_back(y);
		else {
			e2[x].push_back(make_pair(y, eid));
			e2[y].push_back(make_pair(x, -eid));
			eid++;
		}
	}
	eid --;
	
	cnt = 0;
	memset(v, false, sizeof v);
	dfs_ma(st);
	o();
	
	cnt = 0;
	memset(v, false, sizeof v);
	dfs_mi(st);
	o();
	
	return 0;
}