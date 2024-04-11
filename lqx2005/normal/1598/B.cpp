#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))

using namespace std;
const int N = 1000 + 10;
int n;
int vis[N][5];
int main() {
	int T;
	for(cin >> T; T--; ) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < 5; j++) {
				cin >> vis[i][j];
			}
		}
		int flag = 0;
		for(int A = 0; A < 5; A++) {
			for(int B = A + 1; B < 5; B++) {
				int c[2][2] = {0};
				for(int i = 1; i <= n; i++) {
					c[vis[i][A]][vis[i][B]]++;
				}
				if(c[0][0]) continue;
				if(c[1][0] > n / 2 || c[0][1] > n / 2) continue;
				flag = 1;
				break;
			}
			if(flag) break;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}