#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int M = N * N;
const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int a[N];
int f[N];
int nxt[M][2];

int main() {
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i + 1] = 1;
		int nw = 0;
		for (int j = i; j > 0; --j) {
			int len = min(4, i - j + 1);
			if (len == 4) {
				int hsh = a[j] * 8 + a[j + 1] * 4 + a[j + 2] * 2 + a[j + 3];
				if (hsh == 3 || hsh == 5 || hsh == 14 || hsh == 15) {
					--len;
				}
			}
			
			f[j] = 0;
			for (int k = 1; k <= len; ++k) {
				add(f[j], f[j + k]);
			}
			if (nxt[nw][a[j]] == 0) {
				nxt[nw][a[j]] = ++cnt;
				add(ans, f[j]);
			}
			nw = nxt[nw][a[j]];
		}
		
		cout << ans << '\n';
	}
}