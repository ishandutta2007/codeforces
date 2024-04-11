#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;
#define ls t << 1
#define rs (t << 1) | 1

const int maxn = 800005;
int n, q;
int a[maxn], w[maxn];
ll sum[maxn];
int s2[maxn];
ll s;
int md;
int x, y;

void build(int t, int l, int r){
	if(l == r){
		sum[t] = w[l];
		s2[t] = (ll)a[l] * w[l] % M;
		return;
	}
	int mid = (l + r) >> 1;
	build(t << 1, l, mid);
	build((t << 1) | 1, mid + 1, r);
	sum[t] = sum[ls] + sum[rs];
	s2[t] = (s2[ls] + s2[rs]) % M;
}

void modify(int t, int l, int r, int x, int v){
	if(l == r){
		sum[t] = v;
		s2[t] = (ll)a[l] * v % M;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(ls, l, mid, x, v);
	else modify(rs, mid + 1, r, x, v);
	sum[t] = sum[ls] + sum[rs];
	s2[t] = (s2[ls] + s2[rs]) % M;
}

ll getsum(int t, int l, int r, int x, int y){
	if(l >= x && r <= y) return sum[t];
	int mid = (l + r) >> 1;
	return (x <= mid ? getsum(ls, l, mid, x, y) : 0) +
		(y > mid ? getsum(rs, mid + 1, r, x, y) : 0);
}

void find_mid(int t, int l, int r, int x, int y){
	int mid = (l + r) >> 1;
	
	if(l >= x && r <= y){
		if(sum[t] < s) s -= sum[t];
		else{
			if(l == r) { md = l; s = 0; return; }
			if(sum[ls] < s){
				s -= sum[ls];
				find_mid(rs, mid + 1, r, x, y);
			}else{
				find_mid(ls, l, mid, x, y);
			}
		}
		return;
	}

	if(x <= mid) find_mid(ls, l, mid, x, y);
	if(y > mid && s) find_mid(rs, mid + 1, r, x, y);
}

pii cal_cnt(int t, int l, int r, int x, int y){
	if(l >= x && r <= y) return mkp(sum[t] % M, s2[t]);
	int mid = (l + r) >> 1;
	auto tmp1 = x <= mid ? cal_cnt(ls, l, mid, x, y) : mkp(0, 0);
	auto tmp2 = y > mid ? cal_cnt(rs, mid + 1, r, x, y) : mkp(0, 0);
	return mkp((tmp1.fi + tmp2.fi) % M, (tmp1.se + tmp2.se) % M);
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), a[i] -= i;
	for(int i = 1; i <= n; ++i) scanf("%d", w + i);

	build(1, 1, n);

	while(q--){
		scanf("%d%d", &x, &y);
		if(x < 0){
			modify(1, 1, n, -x, y);
		}else{
			s = getsum(1, 1, n, x, y);
			s = (s + 1) / 2;
			find_mid(1, 1, n, x, y);

			auto tmp1 = cal_cnt(1, 1, n, x, md);
			auto tmp2 = md < y ? cal_cnt(1, 1, n, md + 1, y) : mkp(0, 0);

			int res = (tmp2.se - tmp1.se + (ll)(tmp1.fi - tmp2.fi) * a[md]) % M;
			if(res < 0) res += M;

			printf("%d\n", res);
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}