# include <iostream>
# include <cstdio>
using namespace std;

const int Mod = 1000000007;

int a[1200];

int C[1200][1200];

void pre() {
	C[0][0] = 1;
	for(int i = 1; i < 1200; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) 
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % Mod;
	}
}

int main() {
	pre();
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ans = 1;
	int cur = 0;
	for(int i = 0; i < n; ++i) {
		ans = ans * C[cur + a[i] - 1][a[i] - 1] % Mod;
		cur += a[i];
	}
	cout << ans << endl;
}