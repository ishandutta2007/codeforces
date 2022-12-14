#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef pair <int, int> pii;
typedef long long int LL;
const LL MOD = 1000000007LL, BASE = 10000019LL;
#define fi first
#define se second

struct sgtNode{
	LL dp[1003];
	sgtNode(){memset(dp, 0, sizeof(dp));}
};
typedef sgtNode *tnode;
tnode root[65537];
vector <int> tag[65537];
pii exhibit[15005];
int n, m, ql, qr, qv, st[15005], ed[15005], curTime, Q, q[30005];
LL *temp;

void sgtMark(int x, int l, int r){
	if(l >= ql && r <= qr){
		tag[x].push_back(qv);
		return;
	} int mid = (l + r) >> 1;
	if(ql <= mid) sgtMark(x << 1, l, mid);
	if(qr > mid) sgtMark(x << 1 | 1, mid + 1, r);
}
LL* sgtQuery(int x, int l, int r, int p){
	if(!root[x]){
		root[x] = new sgtNode;
		temp = root[x] -> dp;
		if(x != 1) memcpy(temp, root[x >> 1] -> dp, sizeof(sgtNode));
		while(!tag[x].empty()){
			for(int i = m; i >= exhibit[tag[x].back()].fi; -- i)
				temp[i] = max(temp[i], temp[i - exhibit[tag[x].back()].fi] + exhibit[tag[x].back()].se);
			tag[x].pop_back();
		}
	}
	if(l == r) return root[x] -> dp;
	int mid = (l + r) >> 1;
	if(p <= mid) return sgtQuery(x << 1, l, mid, p);
	return sgtQuery(x << 1 | 1, mid + 1, r, p);
}
int main(){
	int i, j, op, t; LL ans, base, *res;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &exhibit[i].se, &exhibit[i].fi);
		st[i] = i;
	} curTime = n;
	scanf("%d", &Q);
	for(i = 1; i <= Q; ++ i){
		scanf("%d", &op);
		if(op == 1){
			st[++ n] = ++ curTime;
			scanf("%d%d", &exhibit[n].se, &exhibit[n].fi);
		}else if(op == 2){
			scanf("%d", &t);
			ed[t] = ++ curTime;
		}else q[++ q[0]] = curTime;
	}
	for(i = 1; i <= n; ++ i){
		if(!ed[i]) ed[i] = curTime + 1;
		ql = st[i], qr = ed[i] - 1, qv = i;
		sgtMark(1, 1, curTime);
	}
	for(i = 1; i <= q[0]; ++ i){
		res = sgtQuery(1, 1, curTime, q[i]);
		for(j = 1, base = 1LL, ans = 0LL; j <= m; ++ j){
			ans = (ans + ((res[j]) % MOD * base)) % MOD;
			base = (base * BASE) % MOD;
		}
		printf("%d\n", int(ans));
	}
	return 0;
}