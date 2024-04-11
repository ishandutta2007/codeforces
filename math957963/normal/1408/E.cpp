#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define N 500010
#define MOD 998244353

int p[N];
int d[N];

void init(void) {
	rep(i, N) {
		p[i] = i;
		d[i] = 1;
	}
	return;
}

int pa(int x) {
	if (p[x] == x)return x;
	else return p[x] = pa(p[x]);
}

bool jud(int x, int y) {
	if (pa(x) == pa(y))return true;
	return false;
}


void uni(int x, int y) {
	int px = pa(x);
	int py = pa(y);
	if (px == py)return;
	if (d[px] < d[py]) {
		p[px] = py;
		d[py] = max(d[py], d[px] + 1);
	}
	else {
		p[py] = px;
		d[px] = max(d[px], d[py] + 1);
	}
	return;
}


int main() {
	int n, m, k, x, sz;
	cin >> n >> m;
	long long a[N];
	long long b[N];
	int p[N];
	long long ans;
	vector<pair<long long, pii> >c;
	rep(i, n)cin >> a[i];
	rep(i, m)cin >> b[i];
	rep(i, n)p[i] = -1;
	rep(i, n) {
		cin >> k;
		rep(j, k) {
			cin >> x;
			x--;
			c.push_back({ a[i] + b[x],{i,x} });
		}
	}
	sort(all(c), greater<pair<long long, pii> >());
	init();
	sz = c.size();
	rep(i, sz) {
		x = c[i].second.first;
		if (p[x] != -1) {
			if (jud(p[x], c[i].second.second)) {
				ans += c[i].first;
			}
			else uni(p[x], c[i].second.second);
		}
		p[x] = c[i].second.second;
	}
	cout << ans << endl;
	return 0;
}