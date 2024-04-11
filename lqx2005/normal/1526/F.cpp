#include <bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e5 + 10;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int p[N];
int ask(int a, int b, int c) {
	cout << "? " << a <<" " << b <<" " << c << endl;
	int y;
	cin >> y;
	return y;
}

void solve() {
	int n;
	cin >> n;
	int a, b, c;
	uniform_int_distribution<> dist(1, n);
	do {
		a = dist(rnd);
		do {
			b = dist(rnd);
		} while(a == b);
		do {
			c = dist(rnd);
		} while(a == c || b == c);
	} while(ask(a, b, c) >= n / 6);
	memset(p, 0, (n + 1) << 2);
	for(int i = 1; i <= n; i++) if(a != i && b != i) p[i] = ask(i, a, b);
	int p0 = max_element(p + 1, p + n + 1) - p;
	int p1 = -1;
	for(int i = 1; i <= n; i++) {
		if(i != a && i != b && p[i] + 1 == p[p0] && (p1 == -1 || ask(p0, p1, a) > ask(p0, i, a))) {
			p1 = i;
		}
	}
	p[p0] = 1, p[p1] = 2;
	for(int i = 1; i <= n; i++) {
		if(i != p0 && i != p1) {
			p[i] = ask(p0, p1, i) + 2;
		}
	}
	if(p[1] > p[2]) {
		for(int i = 1; i <= n; i++) {
			p[i] = n + 1 - p[i];
		}
	}
	cout << "!";
	for(int i = 1; i <= n; i++) {
		cout << " " << p[i];
	}
	cout << endl;
	int ans;
	cin >> ans;
	assert(ans == 1);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; solve()); 
	return 0;
}