#include <cstdio>
const int MAXN = 1000005;

struct treeNode{
	int zz, oo, oz, zo, rev;
}tree[MAXN << 2];
int n, m;
char buf[MAXN];

inline int max(int a, int b){return a > b ? a : b;}
inline void swap(int& a, int& b){int t = a; a = b; b = t;}
void maintain(int x){
	 tree[x].oo = tree[x << 1].oo + tree[x << 1 | 1].oo;
	 tree[x].zz = tree[x << 1].zz + tree[x << 1 | 1].zz;
	 tree[x].zo = max(tree[x << 1].zo + tree[x << 1 | 1].oo, tree[x << 1].zz + tree[x << 1 | 1].zo);
	 tree[x].oz = max(tree[x << 1].oz + tree[x << 1 | 1].zz, tree[x << 1].oo + tree[x << 1 | 1].oz);
}
void reverse(int x){
	swap(tree[x].zo, tree[x].oz);
	swap(tree[x].zz, tree[x].oo);
	tree[x].rev ^= 1;
}
void pushDown(int x){
	if(tree[x].rev){
		reverse(x << 1);
		reverse(x << 1 | 1);
		tree[x].rev = false;
	}
}
void buildTree(int x, int l, int r){
	if(l == r){
		tree[x].zo = tree[x].oz = 1;
		if(buf[l] == '4') tree[x].zz = 1;
		else tree[x].oo = 1;
		return;
	}
	int mid = (l + r) >> 1;
	buildTree(x << 1, l, mid);
	buildTree(x << 1 | 1, mid + 1, r);
	maintain(x);
}
void update(int x, int l, int r, int ql, int qr){
	if(l >= ql && r <= qr){
		reverse(x);
		return;
	}
	pushDown(x);
	int mid = (l + r) >> 1;
	if(ql <= mid) update(x << 1, l, mid, ql, qr);
	if(qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr);
	maintain(x);
}
int main(){
	int i, l, r;
	scanf("%d%d%s", &n, &m, buf + 1);
	buildTree(1, 1, n);
	for(i = 1; i <= m; ++ i){
		scanf("%s", buf + 1);
		if(buf[1] == 'c') printf("%d\n", tree[1].zo);
		else{
			scanf("%d%d", &l, &r);
			update(1, 1, n, l, r);
		}
	}
	return 0;
}