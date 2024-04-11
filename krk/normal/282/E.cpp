#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxb = 40;

struct trie {
	vector <int> ind;
	trie *nil, *one;
	trie() { nil = one = NULL; }
};

int n;
ll a[Maxn];
ll rxor[Maxn];
trie tr;
ll res;

void Insert(trie &tr, int b, const ll &val, int in)
{
	tr.ind.push_back(in);
	if (b < 0) return;
	if (val & 1ll << b) {
		if (tr.one == NULL) tr.one = new trie();
		Insert(*tr.one, b - 1, val, in);
	} else {
		if (tr.nil == NULL) tr.nil = new trie();
		Insert(*tr.nil, b - 1, val, in);
	}
}

ll Get(trie &tr, int b, const ll &val, int in)
{
	if (b < 0) return 0ll;
	if (val & 1ll << b)
		if (tr.nil != NULL && tr.nil->ind.back() > in)
			return Get(*tr.nil, b - 1, val, in) ^ 1ll << b;
		else return Get(*tr.one, b - 1, val, in);
	else if (tr.one != NULL && tr.one->ind.back() > in)
			return Get(*tr.one, b - 1, val, in) ^ 1ll << b;
		else return Get(*tr.nil, b - 1, val, in);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = n - 1; i >= 0; i--)
		rxor[i] = a[i] ^ rxor[i + 1];
	for (int i = 0; i <= n; i++)
		Insert(tr, Maxb - 1, rxor[i], i);
	ll cur = 0ll;
	res = Get(tr, Maxb - 1, cur, -1);
	for (int i = 0; i < n - 1; i++) {
		cur ^= a[i];
		res = max(res, Get(tr, Maxb - 1, cur, i));
	}
	printf("%I64d\n", res);
	return 0;
}