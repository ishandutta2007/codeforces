#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll maxn = 2e5 + 10;
ll T,n,x[maxn],sum;
struct node {
	ll a,id;
	bool operator < (const node &p) { return a > p.a; }
}v[maxn];

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		for(ll i = 1; i <= n; ++i) scanf("%lld", &v[i].a), v[i].id = i;
		sort(v + 1, v + n + 1);
		for(ll i = 1, l = -1, r = 1; i <= n; ++i) {
			if(i & 1) x[v[i].id] = r++;
			else x[v[i].id] = l--;
			sum += 2 * v[i].a * abs(x[v[i].id]);
		}
		printf("%lld\n", sum);
		for(int i = 0; i <= n; ++i)
			printf("%lld%c", x[i], " \n"[i == n]);
		sum = 0;
	}
	return 0;
}