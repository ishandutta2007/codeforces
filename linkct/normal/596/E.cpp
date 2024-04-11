#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 205, MAXLEN = 1000005, MAXNODE = 40005, SIGMA = 15;
typedef pair <int, int> pii;
#define fi first
#define se second

int n, m, q, vis[MAXNODE], nodeSize, root[MAXNODE], len;
int ringID, rid[MAXNODE], ch[MAXNODE][SIGMA], dfsClock;
int last[SIGMA];
bool charset[MAXNODE][SIGMA];
char buf[MAXLEN], str[MAXN][MAXN];
vector <int> to[MAXNODE];
pii ret, delta[15];

inline bool inmap(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= m;}
inline int pack(int x, int y){return (x - 1) * m + y;}
inline void unpack(int x){
	ret.fi = (x - 1) / m + 1;
	ret.se = (x - 1) % m + 1;
}
bool dfs(int x){
	vis[x] = dfsClock;
	for(int i = 0; i < int(to[x].size()); ++ i){
		if(vis[to[x][i]]){
			if(vis[to[x][i]] != dfsClock) continue;
			rid[x] = ++ ringID;
			unpack(x);
			charset[ringID][str[ret.fi][ret.se] - '0'] = true;
			return true;
		}else if(dfs(to[x][i])){
			rid[x] = ringID;
			unpack(x);
			charset[ringID][str[ret.fi][ret.se] - '0'] = true;
			return true;
		}
	}
	return false;
}
void dfsIns(int x, int &rt){
	if(!rt) rt = ++ nodeSize;
	for(int i = 0; i < int(to[x].size()); ++ i)
		if(!rid[to[x][i]]){
			unpack(to[x][i]);
			dfsIns(to[x][i], ch[rt][str[ret.fi][ret.se] - '0']);
		}
}
int dfsDP(int x){
	int res = 0, i, tmp;
	for(i = 0; i < 10; ++ i)
		if(ch[x][i]){
			tmp = dfsDP(ch[x][i]);
			if(tmp < len && buf[tmp + 1] == i + '0') ++ tmp;
			if(tmp > res) res = tmp;
		}
	return res;
}
int main(){
	int i, j, k, border, tmp, nx, ny; bool flag;
	scanf("%d%d%d", &n, &m, &q);
	for(i = 1; i <= n; ++ i)
		scanf("%s", str[i] + 1);
	for(i = 0; i < 10; ++ i)
		scanf("%d%d", &delta[i].fi, &delta[i].se);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j){
			nx = i + delta[str[i][j] - '0'].fi;
			ny = j + delta[str[i][j] - '0'].se;
			if(inmap(nx, ny)){
				to[pack(nx, ny)].push_back(pack(i, j));
			}
			else to[pack(i, j)].push_back(pack(i, j));
		}
	for(i = 1; i <= n * m; ++ i)
		if(!vis[i]) ++ dfsClock, dfs(i);
	for(i = 1; i <= n * m; ++ i){
		if(!rid[i]) continue;
		dfsIns(i, root[rid[i]]);
	}
	for(i = 1; i <= q; ++ i){
		scanf("%s", buf + 1);
		len = strlen(buf + 1);
		memset(last, 0, sizeof(last));
		for(j = len; j; -- j)
			if(!last[buf[j] - '0'])
				last[buf[j] - '0'] = j;
		for(j = 1, flag = false; j <= ringID; ++ j){
			tmp = dfsDP(root[j]);
			for(k = border = 0; k < 10; ++ k)
				if(!charset[j][k]) border = max(border, last[k]);
			if(tmp >= border) flag = true;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}