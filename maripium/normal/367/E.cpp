#include <bits/stdc++.h>
using namespace std;

const int N = 320;
const int mod = 1e9 + 7;

int n, m, x;
int f[2][N][N][2];

void add(int &x, int y) { x = x + y < mod ? x + y : x + y - mod; }

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> x;
	if (n > m) return cout << 0 << '\n',0;
	
	f[0][0][0][0] = 1;
	for (int pos = 0; pos <= m - 1; ++pos) {
		for (int was = 0; was <= n; ++was) {
			for (int cnt = 0; cnt <= was; ++cnt) {
				for (int ok = 0; ok <= 1; ++ok) {
					if (!f[0][was][cnt][ok]) continue;
					
					add(f[1][was][cnt][ok], f[0][was][cnt][ok]);
					
					if (cnt > 0 && pos > 0) add(f[1][was][cnt - 1][ok], f[0][was][cnt][ok]);
							
					if (cnt < n && was < n) {
						if (pos + 1 == x) add(f[1][was + 1][cnt + 1][1], f[0][was][cnt][ok]);
						else add(f[1][was + 1][cnt + 1][ok], f[0][was][cnt][ok]);
						
						if (pos + 1 == x) add(f[1][was + 1][cnt][1], f[0][was][cnt][ok]);
						else add(f[1][was + 1][cnt][ok], f[0][was][cnt][ok]);
					} 
				}
			}
		}
		
		for (int was = 0; was <= n ;++was) {
			for (int cnt = 0; cnt <= was; ++cnt) {
				for (int ok = 0; ok <= 1; ok++) {
					f[0][was][cnt][ok] = f[1][was][cnt][ok];
					f[1][was][cnt][ok] = 0;
				}
			}
		}
	} 
	
	int res = f[0][n][0][1];
	for (int i = 1; i <= n; ++i) res = 1LL * res * i % mod;
	cout << res << '\n';
}