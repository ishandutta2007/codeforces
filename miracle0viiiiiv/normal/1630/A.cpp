#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k, to[65536];
void solve()
{
	scanf("%d%d", &n, &k);
	int b = 0;
	while(n >> b) b ++;
	n = b - 1;
	rep(i, 1 << n) to[i] = (1 << n) - 1 - i;
	if(n == 2 && k == 3) printf("-1\n");
	else {
		int b = k & ((1 << (n - 1)) - 1);
		if(b) {
			swap(to[0], to[b]);
			swap(to[to[0]], to[to[b]]);
		}
		if(k >> (n - 1)) {
			swap(to[1 << (n - 1) | 1], to[1]);
			swap(to[to[1 << (n - 1) | 1]], to[to[1]]);
		}
		rep(i, 1 << n) if(to[i] > i) printf("%d %d\n", i, to[i]);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}