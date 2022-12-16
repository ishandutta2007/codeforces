#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

ll u,v,T;

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &u, &v);
		printf("%lld %lld\n", - u * u, v * v);
	}
	return 0;
}