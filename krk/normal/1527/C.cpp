#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
map <int, ll> M;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		M.clear();
		ll res = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			res += ll(n - i) * M[a];
			M[a] += i + 1;
		}
		printf("%I64d\n", res);
	}
    return 0;
}