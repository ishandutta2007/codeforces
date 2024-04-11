#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i, l, r) for (int i = (l); i <= (r); ++i)
#define Ford(i, r, l) for (int i = (r); i >= (l); --i) 
using namespace std;

const int nxt[] = {4, 9};

long long n;
int f[49];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(f, 69, sizeof f);
	f[0] = 0; q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		For(i, 0, 1) {
			int v = (u + nxt[i]) % 49;
			if (f[v] > f[u] + 1) {
				f[v] = f[u] + 1;
				q.push(v);
			}
		}
	}
	long long res = 0;
	For(i, 0, 48) if (f[i] <= n) {
		res += n - f[i] + 1;
	}
	cout << res << '\n';
}