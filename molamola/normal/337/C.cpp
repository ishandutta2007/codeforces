#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

const int mod = 1e9 + 9;
int mypow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % mod;
		x = (ll) x * x % mod;
		y >>= 1;
	}
	return res;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int num_wrong = n - m;
	if(num_wrong >= n / k) {
		printf("%d\n", m);
		return 0;
	}
	int r1 = n / k - num_wrong, r2 = m - r1 * k;
	int ans = ((ll)k * (mypow(2, r1 + 1) + mod - 2) + r2) % mod;
	printf("%d\n", ans);
	return 0;
}