#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int lim = 2000000000;
const int Maxn = 100005;
const int Maxm = 100005;
const int Maxt = 1048576;

struct node {
	ll lef, rig, res, siz;
	node(ll lef = 0ll, ll rig = 0ll, ll res = 0ll, ll siz = 0ll): lef(lef), rig(rig), res(res), siz(siz) {}
};

int n;
int x[Maxn];
int m;
int t[Maxm], a[Maxm], b[Maxm];
int nx[Maxn];
vector <int> un;
node st[Maxt];

void Insert(int v, int l, int r, int wh)
{
	if (l == r) { st[v].lef = 0ll; st[v].rig = un[r + 1] - un[l]; st[v].res = 0ll; st[v].siz = 1ll; }
	else {
		int m = l + r >> 1;
		if (wh <= m) Insert(2 * v, l, m, wh);
		else Insert(2 * v + 1, m + 1, r, wh);
		st[v].lef = st[2 * v].lef + ll(un[m + 1] - un[l]) * st[2 * v + 1].siz + st[2 * v + 1].lef;
		st[v].rig = ll(un[r + 1] - un[m + 1]) * st[2 * v].siz + st[2 * v].rig + st[2 * v + 1].rig;
		st[v].res = st[2 * v].res + st[2 * v + 1].res + st[2 * v].siz * st[2 * v + 1].lef + st[2 * v].rig * st[2 * v + 1].siz;
		st[v].siz = st[2 * v].siz + st[2 * v + 1].siz;
	}
}

void Erase(int v, int l, int r, int wh)
{
	if (l == r) { st[v].lef = 0ll; st[v].rig = 0ll; st[v].res = 0ll; st[v].siz = 0ll; }
	else {
		int m = l + r >> 1;
		if (wh <= m) Erase(2 * v, l, m, wh);
		else Erase(2 * v + 1, m + 1, r, wh);
		st[v].lef = st[2 * v].lef + ll(un[m + 1] - un[l]) * st[2 * v + 1].siz + st[2 * v + 1].lef;
		st[v].rig = ll(un[r + 1] - un[m + 1]) * st[2 * v].siz + st[2 * v].rig + st[2 * v + 1].rig;
		st[v].res = st[2 * v].res + st[2 * v + 1].res + st[2 * v].siz * st[2 * v + 1].lef + st[2 * v].rig * st[2 * v + 1].siz;
		st[v].siz = st[2 * v].siz + st[2 * v + 1].siz;
	}
}

node getNode(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return getNode(2 * v, l, m, a, b);
		if (m + 1 <= a) return getNode(2 * v + 1, m + 1, r, a, b);
		node nod1 = getNode(2 * v, l, m, a, m), nod2 = getNode(2 * v + 1, m + 1, r, m + 1, b);
		node nod; 
		nod.lef = nod1.lef + ll(un[m + 1] - un[a]) * nod2.siz + nod2.lef;
		nod.rig = ll(un[b + 1] - un[m + 1]) * nod1.siz + nod1.rig + nod2.rig;
		nod.res = nod1.res + nod2.res + nod1.siz * nod2.lef + nod1.rig * nod2.siz;
		nod.siz = nod1.siz + nod2.siz;
		return nod;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { 
		scanf("%d", &x[i]);
		nx[i] = x[i]; un.push_back(nx[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &t[i], &a[i], &b[i]);
		if (t[i] == 1) { nx[a[i]] += b[i]; un.push_back(nx[a[i]]); }
	}
	sort(un.begin(), un.end());
	un.erase(unique(un.begin(), un.end()), un.end()); un.push_back(lim);
	for (int i = 1; i <= n; i++) {
		nx[i] = lower_bound(un.begin(), un.end(), x[i]) - un.begin();
		Insert(1, 0, un.size() - 2, nx[i]);
	}
	for (int i = 0; i < m; i++)
		if (t[i] == 1) {
			Erase(1, 0, un.size() - 2, nx[a[i]]);
			nx[a[i]] = lower_bound(un.begin(), un.end(), un[nx[a[i]]] + b[i]) - un.begin();
			Insert(1, 0, un.size() - 2, nx[a[i]]);
		} else {
			int l = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
			int r = upper_bound(un.begin(), un.end(), b[i]) - un.begin() - 1;
			if (l > r) printf("0\n");
			else {
				node nod = getNode(1, 0, un.size() - 2, l, r);
				printf("%I64d\n", nod.res);
			}
		}
	return 0;
}