#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

ll n,t;

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		printf("%lld %lld\n", - n + 1, n);
	}
	return 0;
}