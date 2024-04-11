#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a,b,x,T;
bool check(ll a, ll b) {
	if(a < b) swap(a, b);
	if(b == 0) return a == x;
	if(a < x) return 0;
	if(a == x || b == x) return 1;
	if(b < x) return (a - x) % b == 0;
	else return check(b, a % b);
}

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld%lld", &a, &b, &x);
		printf(check(a, b) ? "YES\n" : "NO\n");
	}
	return 0;
}