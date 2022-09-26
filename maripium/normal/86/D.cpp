#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int A = 1e6 + 5;
const int S = 448;

int n,t;
int a[N],cnt[A];
long long ans = 0,res[N];

struct query {
	int l,r,id;
	bool operator < (const query &other) {
		return l / S < other.l / S || (l / S == other.l / S && r / S < other.r / S)
		|| (l / S == other.l / S && r / S == other.r / S && id < other.id);
	}
}q[N];

void add(int x) {
	ans -= 1LL * x * cnt[x] * cnt[x];
	++cnt[x];
	ans += 1LL * x * cnt[x] * cnt[x];
}
void del(int x) {
	ans -= 1LL * x * cnt[x] * cnt[x];
	--cnt[x];
	ans += 1LL * x * cnt[x] * cnt[x];
}
int main() {
	scanf("%d%d",&n,&t);
	for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
	for(int i = 1;i <= t;++i) scanf("%d%d",&q[i].l,&q[i].r), q[i].id = i;
	sort(q + 1,q + 1 + t);
	int L = q[1].l, R = q[1].r;
	for(int i = L; i <= R; i++) add(a[i]), res[q[1].id] = ans;
	
	for(int i = 2; i <= t; i++) {
		if (L < q[i].l) for(int j = L; j < q[i].l;++j) del(a[j]);
		if (L > q[i].l) for(int j = L-1; j >= q[i].l;--j) add(a[j]);
		L = q[i].l;
		if (R < q[i].r) for(int j = R + 1;j <= q[i].r;++j) add(a[j]);
		if (R > q[i].r) for(int j = R; j > q[i].r;--j) del(a[j]);
		R = q[i].r;
		res[q[i].id] = ans; 
	}
	for(int i = 1;i <= t;++i) printf("%lld\n",res[i]);
}