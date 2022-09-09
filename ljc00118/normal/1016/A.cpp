#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; bool fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 200000 + 10;

ll a[N];
ll n, m, now = 0;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		now += a[i];
		printf("%I64d ", now / m);
		now %= m;
	}
	return 0;
}