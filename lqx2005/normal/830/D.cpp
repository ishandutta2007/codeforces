#include <bits/stdc++.h>

using namespace std;
const int N = 400 + 10, P = 1e9 + 7, inv2 = (P + 1) / 2;
int k;
int f[N], g[N];

void Add(int &x, int y) {
	if((x += y) >= P && (x -= P));
}

int main() {
	cin >> k;
	f[0] = f[1] = 1;
	for(int i = 1; i < k; i++) {
		memcpy(g, f, sizeof(f));
		memset(f, 0, sizeof(f));
		for(int j = 0; j <= k; j++) {
			for(int l = 0; l <= k - j; l++) {
				Add(f[j + l], 1ll * g[j] * g[l] % P);
				Add(f[j + l + 1], 1ll * g[j] * g[l] % P);
				Add(f[j + l], 2ll * g[j] % P * g[l] % P * (j + l) % P);
				if(j + l) Add(f[j + l - 1], 2ll * g[j] % P * g[l] % P * j % P * l % P);
				if(j + l) Add(f[j + l - 1], 1ll * g[j] % P * g[l] % P * j % P * (j - 1) % P);
				if(j + l) Add(f[j + l - 1], 1ll * g[j] % P * g[l] % P * l % P * (l - 1) % P);
			}
		}
	}
	cout << f[1] << endl;
	return 0;
}

/*

f[j] = g[k] g[j - k] + g[k]g[j - k - 1] + (2j)g[k]g[j - k] + 2 g[k][g[j - k + 1] j * k

*/