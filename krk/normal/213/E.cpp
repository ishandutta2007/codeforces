#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;

struct pos {
	ii h;
	int cnt;
	pos(ii h = ii(0, 0), int cnt = 0): h(h), cnt(cnt) {}
};

int mod1, mod2;
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int sum1[Maxn], sum2[Maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pos st[Maxm];
int fl[Maxm];
int n, m;
int a[Maxn];
vector <ii> seq;

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

void downOn(int v, int add)
{
	st[v].h.first = (st[v].h.first + ll(add) * sum1[st[v].cnt]) % mod1;
	st[v].h.second = (st[v].h.second + ll(add) * sum2[st[v].cnt]) % mod2;
	fl[v] += add;
}

void Down(int v)
{
	if (fl[v]) {
		downOn(2 * v, fl[v]);
		downOn(2 * v + 1, fl[v]);
		fl[v] = 0;
	}
}

pos Join(const pos &a, const pos &b)
{
	pos c;
	c.h.first = (ll(a.h.first) * pw1[b.cnt] + ll(b.h.first)) % mod1;
	c.h.second = (ll(a.h.second) * pw2[b.cnt] + ll(b.h.second)) % mod2;
	c.cnt = a.cnt + b.cnt;
	return c;
}

void Update(int v, int l, int r, int ind, int val, bool add)
{
	if (l == r)
		if (add) st[v] = pos(ii(val, val), 1);
		else st[v] = pos(ii(0, 0), 0);
	else {
		Down(v);
		int m = l + r >> 1;
		if (ind <= m) Update(2 * v, l, m, ind, val, add);
		else Update(2 * v + 1, m + 1, r, ind, val, add);
		st[v] = Join(st[2 * v], st[2 * v + 1]);
	}
}

int main()
{
	mod1 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
	mod2 = uniform_int_distribution<int>(500000000, 1000000000)(rng);
	arg1 = uniform_int_distribution<int>(1000000, 2000000)(rng);
	arg2 = uniform_int_distribution<int>(1000000, 2000000)(rng);
	while (!Prime(mod1)) mod1++;
	while (!Prime(mod2)) mod2++;
	while (!Prime(arg1)) arg1++;
	while (!Prime(arg2)) arg2++;
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
		sum1[i] = (sum1[i - 1] + pw1[i - 1]) % mod1;
		sum2[i] = (sum2[i - 1] + pw2[i - 1]) % mod2; 
	}
	scanf("%d %d", &n, &m);
	pos myh = pos(ii(0, 0), 0);
	ii sum = ii(0, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		myh = Join(myh, pos(ii(a[i], a[i]), 1));
		sum.first = (sum.first + pw1[i]) % mod1;
		sum.second = (sum.second + pw2[i]) % mod2;
	}
	for (int i = 0; i < m; i++) {
		int b; scanf("%d", &b);
		seq.push_back(ii(b, i));
	}
	sort(seq.rbegin(), seq.rend());
	for (int i = 0; i < n - 1; i++)
		Update(1, 0, m - 1, seq[i].second, n - 1 - i, true);
	int res = 0;
	for (int i = n - 1; i < m; i++) {
		downOn(1, 1);
		Update(1, 0, m - 1, seq[i].second, 1, true);
		if (myh.h == st[1].h) res++;
		Update(1, 0, m - 1, seq[i - (n - 1)].second, n, false); 
	}
	printf("%d\n", res);
    return 0;
}