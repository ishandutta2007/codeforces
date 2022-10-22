#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int seq[Maxn];
int slen;
int n, k;
ll a[2][Maxn];
int cur;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		a[cur][i] = k;
		seq[slen++] = i;
	}
	for (int i = 0; i < 1000; i++) {
		int ask = (seq[uniform_int_distribution<int>(0, slen - 1)(rng)] + 1) % n;
		printf("? %d\n", ask + 1); fflush(stdout);
		ll val; scanf("%I64d", &val);
		int nslen = 0;
		for (int i = 0; i < slen; i++) {
			int ind = (ask - seq[i] + n) % n;
			if (a[cur][ind] == val)
				seq[nslen++] = seq[i];
		}
		slen = nslen;
		if (slen == 1) {
			printf("! %d\n", seq[0] + 1); fflush(stdout);
			return 0;
		}
		for (int j = 0; j < n; j++) {
			ll lef = a[cur][j] / 2;
			ll rig = a[cur][j] - lef;
			if (j == 0) { lef = 0; rig = a[cur][j]; }
			a[!cur][(j - 1 + n) % n] += lef;
			a[!cur][(j + 1) % n] += rig;
			a[cur][j] = 0;
		}
		cur = !cur;
	}
	assert(false);
    return 0;
}