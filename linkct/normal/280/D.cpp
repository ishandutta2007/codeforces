#include <cstdio>
#include <cstring>
const int MAXN = 100005;

struct node{
	int dp[21][4], sum;
	void clear(){
		int i, j;
		for(i = 0; i <= 20; ++ i)
			for(j = 0; j < 4; ++ j)
				dp[i][j] = -0x3f3f3f3f;
	}
	node(){clear();}
}t[MAXN << 2], res, ret;
int n, arr[MAXN], m;

inline int max(int a, int b){return a > b ? a : b;}
node merge(node lft, node rht){
	int i, j;
	ret.clear();
	ret.sum = lft.sum + rht.sum;
	ret.dp[0][0] = 0;
	for(i = 1; i <= 20; ++ i){
		ret.dp[i][0] = rht.dp[i][0];
		ret.dp[i][1] = lft.sum + rht.dp[i][1];
		ret.dp[i][2] = rht.sum + lft.dp[i][2];
		for(j = 1; j <= i; ++ j){
			ret.dp[i][0] = max(ret.dp[i][0], max(lft.dp[j][0] + rht.dp[i - j][0], lft.dp[j][2] + rht.dp[i - j + 1][1]));
			ret.dp[i][1] = max(ret.dp[i][1], max(lft.dp[j][1] + rht.dp[i - j][0], lft.dp[j][3] + rht.dp[i - j + 1][1]));
			ret.dp[i][2] = max(ret.dp[i][2], max(rht.dp[j][2] + lft.dp[i - j][0], rht.dp[j][3] + lft.dp[i - j + 1][2]));
			ret.dp[i][3] = max(ret.dp[i][3], max(lft.dp[j][1] + rht.dp[i - j][2], lft.dp[j][3] + rht.dp[i - j + 1][3]));
		}
	}
	return ret;
}
void build(int x, int l, int r){
	if(l == r){
		t[x].dp[0][0] = 0;
		t[x].dp[1][0] = t[x].dp[1][1] = t[x].dp[1][2] = t[x].dp[1][3] = t[x].sum = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	t[x] = merge(t[x << 1], t[x << 1 | 1]);
}
void sgtUpdate(int x, int l, int r, int pos, int val){
	if(l == r){
		t[x].dp[0][0] = 0;
		t[x].dp[1][0] = t[x].dp[1][1] = t[x].dp[1][2] = t[x].dp[1][3] = t[x].sum = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) sgtUpdate(x << 1, l, mid, pos, val);
	else sgtUpdate(x << 1 | 1, mid + 1, r, pos, val);
	t[x] = merge(t[x << 1], t[x << 1 | 1]);
}
node sgtQuery(int x, int l, int r, int ql, int qr){
	if(l >= ql && r <= qr) return t[x];
	int mid = (l + r) >> 1;
	if(ql > mid) return sgtQuery(x << 1 | 1, mid + 1, r, ql, qr);
	if(qr <= mid) return sgtQuery(x << 1, l, mid, ql, qr);
	return merge(sgtQuery(x << 1, l, mid, ql, qr), sgtQuery(x << 1 | 1, mid + 1, r, ql, qr));
}
int main(){
	int i, type, pos, val, l, r, k, ans, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &arr[i]);
	build(1, 1, n);
	scanf("%d", &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d", &type);
		if(!type){
			scanf("%d%d", &pos, &val);
			sgtUpdate(1, 1, n, pos, val);
		}else{
			scanf("%d%d%d", &l, &r, &k);
			res = sgtQuery(1, 1, n, l, r);
			for(j = ans = 0; j <= k; ++ j)
				ans = max(ans, res.dp[j][0]);
			printf("%d\n", ans);
		}
	}
	return 0;
}