#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35005, MAXM = 55, INF = 0x3f3f3f3f;

int n, m, f[MAXM][MAXN], mx[MAXN << 2], tag[MAXN << 2], col[MAXN], last[MAXN];

inline void update(int x, int v){tag[x] += v, mx[x] += v;}
inline void pushDown(int x){
	if(tag[x]){
		update(x << 1, tag[x]);
		update(x << 1 | 1, tag[x]);
		tag[x] = 0;
	}
}
void sgtInit(int x, int l, int r){
	mx[x] = -INF, tag[x] = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	sgtInit(x << 1, l, mid);
	sgtInit(x << 1 | 1, mid + 1, r);
}
void sgtWrite(int x, int l, int r, int p, int v){
	if(l == r){mx[x] = v; return;}
	int mid = (l + r) >> 1; pushDown(x);
	if(p <= mid) sgtWrite(x << 1, l, mid, p, v);
	else sgtWrite(x << 1 | 1, mid + 1, r, p, v);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
void sgtUpdate(int x, int l, int r, int ql, int qr){
	if(l >= ql && r <= qr){update(x, 1); return;}
	int mid = (l + r) >> 1; pushDown(x);
	if(ql <= mid) sgtUpdate(x << 1, l, mid, ql, qr);
	if(qr > mid) sgtUpdate(x << 1 | 1, mid + 1, r, ql, qr);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
int main(){
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &col[i]);
	for(i = 1; i <= m; ++ i){
		memset(last, 0, sizeof(last));
		for(j = 1; j <= i; ++ j)
			last[col[j]] = j;
		sgtInit(1, 1, n);
		sgtWrite(1, 1, n, i, f[i - 1][i - 1] + 1);
		for(j = i; j < n; ++ j){
			f[i][j] = mx[1];
			sgtWrite(1, 1, n, j + 1, f[i - 1][j]);
			sgtUpdate(1, 1, n, last[col[j + 1]] + 1, j + 1);
			last[col[j + 1]] = j + 1;
		} f[i][n] = mx[1];
	} printf("%d\n", f[m][n]);
	return 0;
}