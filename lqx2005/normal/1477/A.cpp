#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e5 + 10;
int t;
int n;
ll a[N];
int main() {
	scanf("%d", &t);
	for(; t--; ) {
		ll k;
		scanf("%d%lld", &n, &k);
		ll g = 0;
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 2; i <= n; i++) g = __gcd(g, a[i] - a[i - 1]);
		k = (k % g + g) % g;
		a[1] = (a[1] % g + g) % g;
		if(k == a[1]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}