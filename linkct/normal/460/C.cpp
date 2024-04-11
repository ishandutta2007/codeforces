#include <cstdio>
#define MAX 100005
#define lch(x) (x<<1)
#define rch(x) ((x<<1)+1)

inline int min(int a, int b){return a > b ? b : a;}
int n, m, w, seq[MAX];
struct treenode{
	int minv, pos, delta;
};
struct segtree{
	treenode node[MAX * 4];
	inline void pushDown(int x){
		if(node[x].delta){
			node[lch(x)].delta += node[x].delta;
			node[rch(x)].delta += node[x].delta;
			node[lch(x)].minv += node[x].delta;
			node[rch(x)].minv += node[x].delta;
			node[x].delta = 0;
		}
	}
	inline void maintain(int x){
		if(node[lch(x)].minv < node[rch(x)].minv){
			node[x].minv = node[lch(x)].minv;
			node[x].pos = node[lch(x)].pos;
		}else if(node[lch(x)].minv > node[rch(x)].minv){
			node[x].minv = node[rch(x)].minv;
			node[x].pos = node[rch(x)].pos;
		}
		else{
			node[x].minv = node[lch(x)].minv;
			node[x].pos = node[lch(x)].pos;
		}
	}
	void init(int x, int l, int r){
		node[x].delta = 0;
		if(l == r){
			node[x].minv = seq[l];
			node[x].pos = l;
			return;
		}
		int mid = (l + r) >> 1;
		init(lch(x), l, mid);
		init(rch(x), mid + 1, r);
		maintain(x);
	}
	void modify(int x, int l, int r, int ql, int qr){
		if(l >= ql && r <= qr){
			node[x].minv ++;
			node[x].delta ++;
			return;
		}
		pushDown(x);
		int mid = (l + r) >> 1;
		if(ql <= mid)
			modify(lch(x), l, mid, ql, qr);
		if(qr > mid)
			modify(rch(x), mid + 1, r, ql, qr);
		maintain(x);
	}
}segt;

int main(){
	int i;
	scanf("%d%d%d", &n, &m, &w);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &seq[i]);
	segt.init(1, 1, n);
	while(m --)
		segt.modify(1, 1, n, segt.node[1].pos, min(segt.node[1].pos + w - 1, n));
	printf("%d\n", segt.node[1].minv);
	return 0;
}