#include <cstdio>
typedef long long int ll;
const int MAXN = 100005;

int c[MAXN << 2], n, m, ql, qr, qv, tag[MAXN << 2];
ll score[MAXN << 2], delta[MAXN << 2];

inline int abs(int x){return x >= 0 ? x : -x;}
void add(int x, int l, int r, ll v){
	delta[x] += v;
	score[x] += (r - l + 1) * v;
}
void pushDown(int x, int l, int r){
	if(tag[x]){
		tag[x << 1] = tag[x << 1 | 1] = tag[x];
		c[x << 1] = c[x << 1 | 1] = tag[x];
		tag[x] = 0;
	}
	if(delta[x]){
		int mid = (l + r) >> 1;
		add(x << 1, l, mid, delta[x]);
		add(x << 1 | 1, mid + 1, r, delta[x]);
		delta[x] = 0;
	}
}
void maintain(int x){
	score[x] = score[x << 1] + score[x << 1 | 1];
	c[x] = (c[x << 1] == c[x << 1 | 1]) ? c[x << 1] : 0;
}
void sgtUpdate(int x, int l, int r){
	if(l >= ql && r <= qr && c[x]){
		add(x, l, r, abs(c[x] - qv));
		c[x] = tag[x] = qv;
		return;
	}
	pushDown(x, l, r);
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(x << 1, l, mid);
	if(qr > mid) sgtUpdate(x << 1 | 1, mid + 1, r);
	maintain(x);
}
ll sgtQuery(int x, int l, int r){
	if(l >= ql && r <= qr) return score[x];
	pushDown(x, l, r);
	int mid = (l + r) >> 1; ll ret = 0;
	if(ql <= mid) ret += sgtQuery(x << 1, l, mid);
	if(qr > mid) ret += sgtQuery(x << 1 | 1, mid + 1, r);
	return ret;
}
void buildTree(int x, int l, int r){
	if(l == r){
		c[x] = l;
		return;
	}
	int mid = (l + r) >> 1;
	buildTree(x << 1, l, mid);
	buildTree(x << 1 | 1, mid + 1, r);
	c[x] = 0;
}
int main(){
	int i, type;
	scanf("%d%d", &n, &m);
	buildTree(1, 1, n);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &type, &ql, &qr);
		if(type == 1){
			scanf("%d", &qv);
			sgtUpdate(1, 1, n);
		}else printf("%I64d\n", sgtQuery(1, 1, n));
	}
	return 0;
}