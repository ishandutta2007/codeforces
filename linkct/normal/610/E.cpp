#include <cstdio>
#include <cstring>
const int MAXN = 200005;

int ql, qr, n, m, k, ord[MAXN << 2][10][10];
char str[MAXN], lft[MAXN << 2], rht[MAXN << 2], tag[MAXN << 2], qv;

void maintain(int x){
	int i, j;
	for(i = 0; i < 10; ++ i)
		for(j = 0; j < 10; ++ j)
			ord[x][i][j] = ord[x << 1][i][j] + ord[x << 1 | 1][i][j];
	++ ord[x][rht[x << 1] - 'a'][lft[x << 1 | 1] - 'a'];
	lft[x] = lft[x << 1], rht[x] = rht[x << 1 | 1];
}
void buildTree(int x, int l, int r){
	if(l == r){
		lft[x] = rht[x] = str[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildTree(x << 1, l, mid);
	buildTree(x << 1 | 1, mid + 1, r);
	maintain(x);
}
void modify(int x, char v){
	tag[x] = lft[x] = rht[x] = v;
	memset(ord[x], 0, sizeof(ord[x]));
}
void pushDown(int x){
	if(tag[x]){
		modify(x << 1, tag[x]);
		modify(x << 1 | 1, tag[x]);
		tag[x] = 0;
	}
}
void sgtUpdate(int x, int l, int r){
	if(l >= ql && r <= qr){
		modify(x, qv);
		return;
	} pushDown(x);
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(x << 1, l, mid);
	if(qr > mid) sgtUpdate(x << 1 | 1, mid + 1, r);
	maintain(x);
}
int main(){
	int i, j, K, ans, type;
	scanf("%d%d%d%s", &n, &m, &k, str + 1);
	buildTree(1, 1, n);
	for(i = 1; i <= m; ++ i){
		scanf("%d", &type);
		if(type == 1){//modify
			scanf("%d%d%s", &ql, &qr, str + 1);
			qv = str[1];
			sgtUpdate(1, 1, n);
		}else{//query
			scanf("%s", str + 1);
			for(ans = n, j = 1; j <= k; ++ j)
				for(K = j + 1; K <= k; ++ K)
					ans -= ord[1][str[j] - 'a'][str[K] - 'a'];
			printf("%d\n", ans);
		}
	}
	return 0;
}