#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
using namespace std;

const int maxn = 2e5 + 10;
ll n,a[maxn],sum,ans;

priority_queue <ll, vector <ll>, greater <ll> > pq;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum += a[i];
		pq.push(a[i]);
		if(sum < 0) {
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, (ll)pq.size());
	}
	printf("%lld\n", ans);
	return 0;
}