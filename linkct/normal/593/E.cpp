#include <cstdio>
#include <cstring>
typedef long long int LL;
const int MAXN = 23, dx[5] = {-1, 0, 0, 0, 1}, dy[5] = {0, -1, 0, 1, 0};
const LL MOD = 1000000007LL;

int n, m, q, tr[MAXN][MAXN], base[MAXN][MAXN], tmp[MAXN][MAXN];
int ans[MAXN], ans_[MAXN], res[MAXN][MAXN], blocked[MAXN];

void mul(int x[MAXN][MAXN]){
	int i, j, k;
	for(i = 1; i <= n * m; ++ i)
		for(j = 1; j <= n * m; ++ j){
			tmp[i][j] = 0;
			for(k = 1; k <= n * m; ++ k)
				tmp[i][j] = (tmp[i][j] + LL(x[i][k]) * base[k][j]) % MOD;
		}
	memcpy(x, tmp, sizeof(tmp));
}
void getPow(int times){
	int i, j;
	memset(res, 0, sizeof(res));
	for(i = 1; i <= n * m; ++ i) res[i][i] = 1;
	while(times){
		if(times & 1) mul(res);
		mul(base);
		times >>= 1;
	}
	for(i = 1; i <= n * m; ++ i){
		ans_[i] = 0;
		for(j = 1; j <= n * m; ++ j)
			ans_[i] = (ans_[i] + LL(res[i][j]) * ans[j]) % MOD;
	}
	for(i = 1; i <= n * m; ++ i) ans[i] = ans_[i];
}
inline bool inmap(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= m;}
inline int pack(int x, int y){return (x - 1) * m + y;}
inline void rebuild(){
	int i, j, k, x, y, s, t;
	memset(base, 0, sizeof(base));
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j){
			s = pack(i, j);
			for(k = 0; k < 5; ++ k){
				x = i + dx[k], y = j + dy[k];
				if(inmap(x, y) && !blocked[t = pack(x, y)]) base[t][s] = 1;
			}
		}
}
int main(){
	int i, x, y, op, t, s, curTime;
	scanf("%d%d%d", &n, &m, &q); ans[1] = 1;
	for(i = curTime = 1; i <= q; ++ i){
		scanf("%d%d%d%d", &op, &x, &y, &t);
		rebuild(); getPow(t - curTime); curTime = t;
		s = pack(x, y);
		if(op == 1){//query
			printf("%d\n", ans[s]);
		}else{//modify
			if(op == 2) ans[s] = 0;
			blocked[s] = 3 - op;
		}
	}
	return 0;
}