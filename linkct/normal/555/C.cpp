#include <cstdio>
const int MAXN = 200005;
typedef long long int ll;

struct sgtNode{
	int v; sgtNode *l, *r;
	sgtNode(){v = 1; l = r = 0;}
};
typedef sgtNode* tnode;
int n, q, nodeSize;
tnode vertRoot, horiRoot;

inline int max(int a, int b){return a > b ? a : b;}
void sgtUpdate(tnode& x, int l, int r, int ql, int qr, int qv){
	if(!x) x = new sgtNode;
	if(l >= ql && r <= qr){
		x -> v = max(x -> v, qv);
		return;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(x -> l, l, mid, ql, qr, qv);
	if(qr > mid) sgtUpdate(x -> r, mid + 1, r, ql, qr, qv);
}
int sgtQuery(tnode x, int l, int r, int p){
	if(!x) return 1;
	if(l == r) return x -> v;
	int mid = (l + r) >> 1;
	if(p <= mid) return max(x -> v, sgtQuery(x -> l, l, mid, p));
	return max(x -> v, sgtQuery(x -> r, mid + 1, r, p));
}
int main(){
	int i, x, y, border; char type[5];
	scanf("%d%d", &n, &q);
	for(i = 1; i <= q; ++ i){
		scanf("%d%d%s", &y, &x, type);
		if(type[0] == 'U'){
			border = sgtQuery(vertRoot, 1, n, y);
			printf("%d\n", x - border + 1);
			if(border > x) continue;
			sgtUpdate(horiRoot, 1, n, border, x, y + 1);
			sgtUpdate(vertRoot, 1, n, y, y, x + 1);
		}else{
			border = sgtQuery(horiRoot, 1, n, x);
			printf("%d\n", y - border + 1);
			if(border > y) continue;
			sgtUpdate(vertRoot, 1, n, border, y, x + 1);
			sgtUpdate(horiRoot, 1, n, x, x, y + 1);
		}
	}
	return 0;
}