#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int main() {
	int t; scanf("%d", &t);
	rep(tt, t) {
		ll n; scanf("%lld", &n);
		printf("%lld\n", (n+1)/10);
	}
	return 0;
}