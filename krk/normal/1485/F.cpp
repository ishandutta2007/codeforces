#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int T;
int n;
int b[Maxn];
int all;
map <ll, int> M;

int main()
{
	scanf("%d", &T);
	while (T--) {
		all = 1;
		M.clear();
		scanf("%d", &n);
		int b; scanf("%d", &b);
		M[0] = (M[0] + 1) % mod;
		all = 1;
		ll sum = b;
		for (int i = 2; i <= n; i++) {
			scanf("%d", &b);
			ll nsum = sum + b;
			int nw = (all - M[nsum - b] + mod) % mod;
			M[sum] = (M[sum] + nw) % mod;
			all = (all + nw) % mod;
			sum = nsum;
		}
		printf("%d\n", all);
	}
    return 0;
}