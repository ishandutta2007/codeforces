#include <bits/stdc++.h> 
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define VI vector<int> 
#define i64 long long
#define db double
#define sz(a) int((a).size())

using namespace std;
const int N = 1e6 + 10;
int n, k;
int x[N], y[N], id[N];

int cmp(int a, int b) {
	if(x[a] == x[b]) return y[a] < y[b];
	return x[a] < x[b];
}

i64 cross(int a, int o, int b) {
	return 1ll * (x[a] - x[o]) * (y[b] - y[o]) - 1ll * (x[b] - x[o]) * (y[a] - y[o]);
}

db dist(int a, int b) {
	return sqrt(1ll * (x[a] - x[b]) * (x[a] - x[b]) + 1ll * (y[a] - y[b]) * (y[a] - y[b]));
}


int check(int a, int b) {
	for(int i = 1; i <= n; i++) {
		if(i == a || i == b) continue;
		if(cross(a, b, i)) return 0;
	}
	return 1;
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i], id[i] = i;
	if(check(id[2], id[3])) swap(id[1], id[3]);
	else if(check(id[1], id[3])) swap(id[2], id[3]);
	int out = -1;
	for(int i = 3; i <= n; i++) if(cross(id[1], id[2], id[i])) out = id[i];
	swap(id[out], id[n]);
	sort(id + 1, id + n, cmp);
	cout.precision(20), cout << fixed;
	if(k == id[n]) {
		cout << dist(id[1], id[n - 1]) + min(dist(id[1], id[n]), dist(id[n - 1], id[n])) << endl;
		return 0;
	}
	int pos = -1;
	for(int i = 1; i < n; i++) if(id[i] == k) pos = i;
	db res = 1.0 / 0.0;
	db mn = dist(id[n - 1], id[n]);
	if(pos + 1 < n) {
		mn = min(mn, dist(id[n], id[1]) + dist(id[n], id[pos + 1]) - dist(id[1], id[pos + 1]));
		for(int i = pos + 2; i < n; i++) mn = min(mn, dist(id[i - 1], id[n]) + dist(id[i], id[n]) - dist(id[i], id[i - 1]));
	}
	res = min(res, dist(id[1], id[pos]) + dist(id[1], id[n - 1]) + mn);
	mn = dist(id[1], id[n]);
	if(pos - 1 >= 1) {
		mn = min(mn, dist(id[n], id[n - 1]) + dist(id[n], id[pos - 1]) - dist(id[n - 1], id[pos - 1]));
		for(int i = 2; i < pos; i++) mn = min(mn, dist(id[i - 1], id[n]) + dist(id[i], id[n]) - dist(id[i], id[i - 1]));
	}
	res = min(res, dist(id[n - 1], id[pos]) + dist(id[1], id[n - 1]) + mn);
	cout << res << endl;
	return 0;
}