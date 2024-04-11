#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 310000
#define pb push_back
#define ll long long

int main() {
	vector<long long>a[(2 * N)];
	long long p2[32];
	long long n, x, sz, c0, c1, inv, ss, sv, cnt, cnt2;
	long long ans = 0;
	long long invans = 0;
	p2[0] = 1;
	f(i, 31)p2[i + 1] = p2[i] * 2;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a[0].push_back(x);
	}
	cnt = 1;
	for (int i = 30; i >= 0; i--) {
		ss = 0;
		sv = 0;
		cnt2 = 0;
		f(j, cnt) {
			c0 = 0;
			c1 = 0;
			inv = 0;
			sz = a[j].size();
			f(ii, sz) {
				x = a[j][ii] % p2[i + 1];
				if (x >= p2[i]) {
					c1++;
					inv += c0;
				}
				else c0++;
			}
			ss += c0 * c1;
			sv += inv;
			if ((c0 > 0) && (c1 > 0)) {
				f(ii, sz) {
					x = a[j][ii] % p2[i + 1];
					if (x >= p2[i])a[cnt2 + N + 1].pb(a[j][ii]);
					else a[cnt2 + N].pb(a[j][ii]);
				}
				cnt2 += 2;
			}
			else {
				a[cnt2 + N] = a[j];
				cnt2++;
			}
		}
		if ((sv * 2) < ss) {
			ans += p2[i];
			invans += sv;
		}
		else invans += (ss - sv);
		f(j, cnt2) {
			a[j] = a[N + j];
			a[N + j].clear();
		}
		cnt = cnt2;
	}
	printf("%lld %lld\n", invans, ans);

	return 0;
}