#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}

int main() {
	int T;
	cin >>T;
	while (T--) {
		int n, K;
		cin >> n >> K;
		map <int, int> w;
		for (int i = 1; i<= n; i++) {
			int x;
			cin >> x;
			w[x]++;
		}
		int last = -1, st = -1, ans = -1, l = -1;
		for (auto [k, v] : w) {
			if (v >= K) {
				if (last != k - 1) st = k;
				last = k;
				if (ans < k - st) {
					ans = k - st;
					l = st;
				}
			}
			else last = st = -1;
		}
		if (ans == -1) puts("-1");
		else printf("%d %d\n", l, l + ans);
	}
}