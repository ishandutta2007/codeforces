// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;


int q;

bool ok;

int inline get(int x) {
	int cnt = 0;
	for (int i = 0; i < 30; i++)
		if (x >> i & 1) cnt++;
	return cnt;
}

int main() {
	// for (int u = 1; u <= 100; u++) {
	// 	for (int v = 1; v<= 100; v++) {
	// 		if ((u & v) == v) {
	// 			cout << u << " " << v + u << endl;
	// 		}
	// 	}
	// }
	scanf("%d", &q);
	// int u, v;
	// for (u = 1; u <= 100; u++)
	// 	for (v = u; v <= 100; v++) {
	// 		int tt = u, ttt = v;
	 while (q--) {
		int u, v; scanf("%d%d", &u, &v);
		if (u > v) puts("NO"); 
		else if (u == v) puts("YES"); 
		else {
			ok = true;
			int s = 0;
			for (int i = 29; ~i; i--) {
				if (v >> i & 1) {
					s = 0;
					int t = 0;
					for (int k = i; k >= 0; k--) {
						if (u >> k & 1) {
							s++;
						}
						if (v >> k & 1) {
							t++;
						}
					}

					if (s < t) {
						ok = false;
						break;
					}
					s--;

					//u ^= 1 << j;
				} else {
					
				}
			}
			
			

			//u = tt, v = ttt;
			
			puts(ok ? "YES" : "NO");
			
		}
		//cout << u << " " << v << " " << ok << endl; 
	}
	return 0;
}