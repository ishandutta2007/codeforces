#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 50005;
const int Maxp = 350;
const int Maxm = 150;
const int Maxv = 1000001;
const int Maxb = 20;

struct node {
	int mn, mx;
	node *ch[2];
	node() { mn = Maxv; mx = -Maxv; ch[0] = ch[1] = NULL; }
};

int f[Maxv];
int n, m;
int a[Maxn];
int L[Maxn], R[Maxn];
vector <ii> has[Maxm];
int res[Maxn];

void Insert(node *t, int ind, bool asmax, int bt = Maxb - 1)
{
	if (asmax) t->mx = max(t->mx, ind);
	else t->mn = min(t->mn, ind);
	if (bt < 0) return;
	if (f[ind] & 1 << bt) {
		if (!t->ch[1]) t->ch[1] = new node();
		Insert(t->ch[1], ind, asmax, bt - 1);
	} else {
		if (!t->ch[0]) t->ch[0] = new node();
		Insert(t->ch[0], ind, asmax, bt - 1);
	}
}

int Get(node *t, int ind, bool formax, int bt = Maxb - 1)
{
	if (!t) return 0;
	if (bt < 0) return 0;
	int need = !bool(f[ind] & 1 << bt);
	if (t->ch[need] && (formax && t->ch[need]->mx >= ind || 
					    !formax && t->ch[need]->mn <= ind))
		return Get(t->ch[need], ind, formax, bt - 1) + (1 << bt);
	return Get(t->ch[!need], ind, formax, bt - 1);
}

void Erase(node *t)
{
	if (!t) return;
	if (t->ch[0]) { Erase(t->ch[0]); delete t->ch[0]; }
	if (t->ch[1]) { Erase(t->ch[1]); delete t->ch[1]; }
}

int main()
{
	for (int i = 1; i < Maxv; i++)
		f[i] = f[i - 1] ^ i;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &L[i], &R[i]); L[i]--; R[i]--;
		if (R[i] - L[i] <= Maxp) {
			res[i] = 0;
			node *t = new node();
			for (int j = L[i]; j <= R[i]; j++) {
				Insert(t, a[j] - 1, false);
				Insert(t, a[j], true);
				res[i] = max(res[i], max(Get(t, a[j] - 1, true), Get(t, a[j], false)));
			}
			Erase(t); delete t;
		} else {
			int l2 = L[i] / Maxp;
			if (l2 * Maxp != L[i]) l2++;
			has[l2].push_back(ii(R[i], i));
		}
	}
	for (int i = 0; i * Maxp < n; i++) {
		sort(has[i].begin(), has[i].end());
		node *t = new node();
		int grs = 0;
		int nxt = i * Maxp;
		for (int j = 0; j < has[i].size(); j++) {
			ii p = has[i][j];
			while (nxt <= p.first) {
				Insert(t, a[nxt] - 1, false);
				Insert(t, a[nxt], true);
				grs = max(grs, max(Get(t, a[nxt] - 1, true), Get(t, a[nxt], false)));
				nxt++;
			}
			node *t2 = new node(); int rs = grs;
			int my = i * Maxp - 1;
			while (L[p.second] <= my) {
				rs = max(rs, max(Get(t, a[my] - 1, true), Get(t, a[my], false)));
				Insert(t2, a[my] - 1, false);
				Insert(t2, a[my], true);
				rs = max(rs, max(Get(t2, a[my] - 1, true), Get(t2, a[my], false)));
				my--;
			}
			Erase(t2); delete t2;
			res[p.second] = rs;
		}
		Erase(t); delete t;
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", res[i]);
	return 0;
}