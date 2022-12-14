#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

struct sgtNode{
	int l, r, cnt[10][10][4];
}tr[262155];
int n, q, ans, len; char str[MAXN], tmp[15];

inline int get(char x){
	if(x == 'A') return 0;
	if(x == 'T') return 1;
	if(x == 'G') return 2;
	return 3;
}
inline void maintain(int x){
	int lc = x << 1, rc = x << 1 | 1, i, j, k, v;
	memcpy(tr[x].cnt, tr[lc].cnt, sizeof(tr[x].cnt));
	for(i = 1; i <= 10; ++ i)
		for(j = 0, k = (tr[rc].l - tr[x].l) % i; j < i; ++ j, k = (k + 1 == i ? 0 : (k + 1)))
			for(v = 0; v < 4; ++ v)
				tr[x].cnt[i - 1][k][v] += tr[rc].cnt[i - 1][j][v];
}
void sgtBuild(int x, int l, int r){
	tr[x].l = l, tr[x].r = r;
	if(l == r){
		for(int i = 0; i < 10; ++ i)
			++ tr[x].cnt[i][0][str[r]];
		return;
	} int mid = (l + r) >> 1;
	sgtBuild(x << 1, l, mid);
	sgtBuild(x << 1 | 1, mid + 1, r);
	maintain(x);
}
void sgtUpdate(int x, int p, int v){
	int i, j;
	for(i = 0; i < 10; ++ i){
		j = (p - tr[x].l) % (i + 1);
		-- tr[x].cnt[i][j][str[p]];
		++ tr[x].cnt[i][j][v];
	}
	if(tr[x].l == tr[x].r) return;
	if(p <= ((tr[x].l + tr[x].r) >> 1))
		sgtUpdate(x << 1, p, v);
	else sgtUpdate(x << 1 | 1, p, v);
}
void sgtQuery(int x, int ql, int qr){
	if(tr[x].l >= ql && tr[x].r <= qr){
		for(int i = 0, j = (tr[x].l - ql) % len; i < len; ++ i, j = (j + 1 == len ? 0 : (j + 1)))
			ans += tr[x].cnt[len - 1][i][tmp[j]];
		return;
	} int mid = (tr[x].l + tr[x].r) >> 1;
	if(ql <= mid) sgtQuery(x << 1, ql, qr);
	if(qr > mid) sgtQuery(x << 1 | 1, ql, qr);
}
int main(){
	int i, j, l, r, op;
	scanf("%s%d", str + 1, &q);
	n = strlen(str + 1);
	for(i = 1; i <= n; ++ i)
		str[i] = get(str[i]);
	sgtBuild(1, 1, n);
	for(i = 1; i <= q; ++ i){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d%s", &j, tmp);
			tmp[0] = get(tmp[0]);
			sgtUpdate(1, j, tmp[0]);
			str[j] = tmp[0];
		}else{
			scanf("%d%d%s", &l, &r, tmp);
			len = strlen(tmp);
			for(j = 0; j < len; ++ j)
				tmp[j] = get(tmp[j]);
			ans = 0; sgtQuery(1, l, r);
			printf("%d\n", ans);
		}
	} return 0;
}