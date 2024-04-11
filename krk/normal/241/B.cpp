#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 30;
const int Maxn = 50004;
const int mod = 1000000007;

struct node {
	int cnt;
	int ones[Maxb];
	node* ch[2];
	node() {
		cnt = 0;
		fill(ones, ones + Maxb, 0);
		ch[0] = ch[1] = nullptr;
	}
};

int n;
ll m;
int a[Maxn];
node *tr;

void Add(node *tr, int lvl, int num)
{
	tr->cnt++;
	for (int i = 0; i < Maxb; i++)
		if (num & 1 << i) tr->ones[i]++;
	if (lvl < 0) return;
	int ind = bool(num & 1 << lvl);
	if (!tr->ch[ind]) tr->ch[ind] = new node();
	Add(tr->ch[ind], lvl - 1, num);
}

ll Get(node *tr, int lvl, int num, int nd)
{
	if (lvl < 0) return tr->cnt;
	int fir = !bool(num & 1 << lvl);
	int sec = bool(num & 1 << lvl);
	if (nd & 1 << lvl)
		if (tr->ch[fir]) return Get(tr->ch[fir], lvl - 1, num, nd);
		else return 0;
	else {
		ll res = 0;
		if (tr->ch[fir]) res += tr->ch[fir]->cnt;
		if (tr->ch[sec]) res += Get(tr->ch[sec], lvl - 1, num, nd);
		return res;
	}
}

int addBits(int mask, node *tr)
{
	int res = 0;
	for (int i = 0; i < Maxb; i++)
		if (mask & 1 << i)
			res = (res + ll(1 << i) * (tr->cnt - tr->ones[i])) % mod;
		else res = (res + ll(1 << i) * tr->ones[i]) % mod;
	return res;
}

int getSum(node *tr, int lvl, int num, int nd)
{
	if (lvl < 0) return addBits(num, tr);
	int fir = !bool(num & 1 << lvl);
	int sec = bool(num & 1 << lvl);
	if (nd & 1 << lvl)
		if (tr->ch[fir]) return getSum(tr->ch[fir], lvl - 1, num, nd);
		else return 0;
	else {
		int res = 0;
		if (tr->ch[fir]) res = (res + addBits(num, tr->ch[fir])) % mod;
		if (tr->ch[sec]) res = (res + getSum(tr->ch[sec], lvl - 1, num, nd)) % mod;
		return res;
	}
}

int main()
{
	tr = new node();
	scanf("%d %I64d", &n, &m);
	if (m == 0) { printf("0\n"); return 0; }
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		Add(tr, Maxb - 1, a[i]);
	}
	int lef = 0, rig = (1 << Maxb) - 1;
	while (lef <= rig) {
		ll mid = (ll(lef) + ll(rig)) / 2ll;
		ll got = 0;
		for (int i = 0; i < n; i++)
			got += Get(tr, Maxb - 1, a[i], mid + 1);
		got /= 2;
		if (got < m) rig = mid - 1;
		else lef = mid + 1;
	}
	ll mid = lef + 1;
	ll got = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		got += Get(tr, Maxb - 1, a[i], mid);
		sum = (sum + getSum(tr, Maxb - 1, a[i], mid)) % mod;
	}
	got /= 2;
	sum = ll(sum) * 500000004ll % mod;
	sum = (sum + (m - got) % mod * ll(lef)) % mod;
	printf("%d\n", sum);
    return 0;
}