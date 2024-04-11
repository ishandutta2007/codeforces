#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int S = 317;
const int K = 1 << 20;

struct data {
	int l, r, id;
	bool operator < (const data &rhs) const {
		return l / S < rhs.l / S || (l / S == rhs.l / S && r / S < rhs.r / S);
	}
} query[N];

int n, q, k;
int a[N], cnt[K];
int res[N];
int cur = 0;
void add(int x) {
    int tmp = k ^ a[x];
    cur += cnt[tmp];
    cnt[a[x]]++;
}

void del(int x) {
    cnt[a[x]]--;
    int tmp = k ^ a[x];
    cur -= cnt[tmp];
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) a[i] ^= a[i - 1];
	for (int i = 1;i <= q;++i) {
		cin >> query[i].l >> query[i].r;
		--query[i].l;
		query[i].id = i;
	}
	sort(query + 1, query + 1 + q);
	int L = 0, R = 0; add(0);
	for (int i = 1;i <= q;++i) {
		int l = query[i].l, r = query[i].r;
		while(L > l) add(--L);
		while(R < r) add(++R);
		while(L < l) del(L++);
		while(R > r) del(R--);
		res[query[i].id] = cur; 
	}
	
	for (int i = 1;i <= q;++i) cout << res[i] << '\n';
}