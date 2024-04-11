#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	if(!f) return n;
	else return -n;
}

const int N = 1000005;

vector <int> vc;

int tn, n, ansx, ansy, a[N], cnt[N];

double minn;

int main() {
	cin >> tn;
	while(tn--) {
		scanf("%d", &n);
		minn = LONG_LONG_MAX;
		vc.clear();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			cnt[a[i]] += 2; cnt[a[i]]--;
			if (cnt[a[i]] == 2) vc.push_back(a[i]);
			if (cnt[a[i]] == 4) {
				minn = 0.000000000001;
				ansx = a[i] + 1;
				ansy = a[i];
				ansx--;
			}
		}
		sort(vc.begin(), vc.end());
		for (int i = 1; i < vc.size(); i++) {
			int x = vc[i - 1], y = x + vc[i] - vc[i - 1];
			if (minn > (double)(x + y) * (double)(x + y) / (double)x / (double)y) {
				minn = (double)(x + y) * (double)(x + y) / x / y;
				ansx = x;
				ansy = y;
			}
		}
		cout << ansx << " " << ansy << " " << ansx << " " << ansy << endl;
		for (int i = 1; i <= n; i++) cnt[a[i]]--;
	}
	return 0;
}