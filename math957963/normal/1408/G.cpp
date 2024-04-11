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
#define N 1510
#define M 1200000
#define MOD 998244353

int p[N];
int d[N];
int a[N];
int pp[N];
vector<long long>ans[M];
vector<int>unuse;
int anc[M];
int b[M];
int c[M];
int cur;
void init(void) {
	rep(i, N) {
		p[i] = i;
		d[i] = 1;
		a[i] = 0;
		pp[i] = 1;
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
		a[py] += a[px];
		a[px] = 0;
		pp[py] += pp[px];
		pp[px] = 0;
		d[py] = max(d[py], d[px] + 1);
	}
	else {
		p[py] = px;
		a[px] += a[py];
		a[py] = 0;
		pp[px] += pp[py];
		pp[py] = 0;
		d[px] = max(d[px], d[py] + 1);
	}
	return;
}


int main() {
	int n, x, m, sz, np;
	int sz1, sz2;
	vector<long long>aa;
	vector<long long>na;
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> x;
			if (x != 0) {
				b[x - 1] = i;
				c[x - 1] = j;
			}
		}
	}
	init();
	rep(i, n) {
		ans[i].push_back(0);
		ans[i].push_back(1);
		anc[i] = i;
		unuse.push_back(i);
	}
	cur = n;
	m = n * (n - 1);
	m = m / 2;
	rep(i, m) {
		if (pa(b[i]) != pa(c[i]))uni(b[i], c[i]);
		np = pa(b[i]);
		a[np]++;
		x = pp[np];
		x = x * (x - 1);
		x /= 2;
		if (x == a[np]) {
			aa.clear();
			aa.push_back(1);
			x = 0;
			while (true) {
				sz = unuse.size();
				if (x >= sz)break;
				if (pa(anc[unuse[x]]) == np) {
					sz1 = ans[unuse[x]].size();
					sz2 = aa.size();

					na.clear();
					rep(ii, sz1 + sz2 - 1)na.push_back(0);
					rep(ii, sz1) {
						rep(jj, sz2) {
							na[ii+jj] = (na[ii+jj] + (ans[unuse[x]][ii] * aa[jj])) % MOD;
						}
					}
					aa = na;
					unuse.erase(unuse.begin() + x);
				}
				else x++;
			}
			sz = aa.size();
			aa[1] = 1;
			ans[cur] = aa;
          anc[cur]=np;
			unuse.push_back(cur);
			cur++;
		}
	}
	cur--;
	rep(i, n - 1)cout << ans[cur][i + 1] << " ";
	cout << ans[cur][n] << endl;


	return 0;
}