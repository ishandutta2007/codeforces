#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

const int TS = 1<<19, ST = TS/2-1;
const int MOD = (int)1e9 + 7, inf = (int)2e9;
int N;
int prefix_max[MAXN];
struct Z{
	int s, e;
} A[MAXN];
struct val_t{
	int v, c;
	val_t operator + (const val_t &ot)const{
		val_t ret = *this;
		if (v > ot.v) ret = ot;
		else if (v == ot.v) ret.c = (c+ot.c)%MOD;
		return ret;
	}
} tree[TS], D[MAXN];

int get_idx(int x)
{
	int s = 1, e = N, ret = 0;
	while (s <= e){
		int m = s+e >> 1;
		if (A[m].e <= x) s = m+1, ret = m;
		else e = m-1;
	}
	return ret;
}

void write(int n, int v, int c)
{
	val_t cur = {v, c};
	n += ST;
	tree[n] = tree[n]+cur;
	for (n>>=1;n;n>>=1) tree[n] = tree[n+n]+tree[n+n+1];
}

val_t get(int l, int r)
{
	val_t ret = {inf, 0};
	for (l+=ST,r+=ST;l<=r;l>>=1,r>>=1){
		if (l&1) ret = ret+tree[l++];
		if (~r&1) ret = ret+tree[r--];
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N; int max_s = 0;
	for (int i=1;i<=N;i++){
		cin >> A[i].e >> A[i].s;
		max_s = max(max_s, A[i].s);
	}
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.e < b.e;
	});
	for (int i=1;i<TS;i++) tree[i] = {inf, 0};
	val_t ans = {inf, 0};
	for (int i=1;i<=N;i++){
		prefix_max[i] = max(prefix_max[i-1], A[i].s);
		int e = get_idx(A[i].s);
		int s_bound = prefix_max[e];
		int s = get_idx(s_bound)+1;
		D[i] = get(s, e);
		if (D[i].v == 2e9) D[i] = {A[i].s, 1};
		else D[i].v += A[i].s;
		write(i, D[i].v-A[i].e, D[i].c);
		if (A[i].e > max_s) ans = ans+D[i];
	}
	cout << ans.c << endl;
}