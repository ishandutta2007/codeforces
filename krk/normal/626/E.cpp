#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

struct frac {
	ll a, b;
	frac(ll a = 0, ll b = 1): a(a), b(b) { }
	bool operator >(const frac &u) const {
		return a * u.b > u.a * b;
	}
};

int n;
int x[Maxn];
ll sum[Maxn];
frac res(-1, 1);
int bind;
vector <int> ans;

bool Check(int m, int ind)
{
	return x[n - m] - x[ind] > x[ind] - x[ind - m];
}

frac Get(int m, int ind) 
{
	ll sm = sum[n - m] + sum[ind - m] - sum[ind + 1];
	return frac(sm - ll(x[ind]) * (2ll * m + 1ll), 2 * m + 1);
}

int getBest(int l, int r, int ind)
{
	if (l == r) return l;
	if (r - l <= 2) {
		frac res = Get(l, ind);
		int bi = l;
		for (int i = l + 1; i <= r; i++) {
			frac cand = Get(i, ind);
			if (cand > res) { res = cand; bi = i; }
		}
		return bi;
	}
	int q1 = (2 * l + r) / 3, q2 = (l + 2 * r) / 3;
	frac a = Get(q1, ind), b = Get(q2, ind);
	if (a > b) return getBest(l, q2, ind);
	else return getBest(q1, r, ind);
}

int getOdd(int ind)
{
	int l = 1, r = min(ind, n - 1 - ind);
	int res = 0;
	while (l <= r) {
		int m = l + r >> 1;
		if (x[n - m] - x[ind] > x[ind] - x[ind - m]) { res = m; l = m + 1; }
		else r = m - 1;
	}
	return getBest(0, res, ind);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	for (int i = n - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + x[i];
	for (int i = 0; i < n; i++) {
		int got = getOdd(i);
		frac cand = Get(got, i);
		if (cand > res) {
			res = cand; bind = i;
		}
	}
	int got = getOdd(bind);
	for (int i = bind - got; i <= bind; i++)
		ans.push_back(x[i]);
	for (int i = n - got; i < n; i++)
		ans.push_back(x[i]);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], i + 1 < ans.size()? ' ': '\n');
	return 0;
}