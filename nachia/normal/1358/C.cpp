#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		ULL x1, x2, y1, y2;
		scanf("%llu%llu%llu%llu", &x1, &y1, &x2, &y2);
		x2 -= x1;
	    y2 -= y1;
		cout << x2 * y2 + 1 << endl;
	}
	return 0;
}