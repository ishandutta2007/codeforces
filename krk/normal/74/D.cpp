#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxq = 100005;

struct interv {
	ii l, r;
	interv() {}
	interv(ii l, ii r): l(l), r(r) { }
	bool operator <(const interv &I) const {
		if (r.first - l.first != I.r.first - I.l.first) return r.first - l.first > I.r.first - I.l.first;
		return l.first > I.l.first;
	}
};

int n, q;
int a[Maxq], b[Maxq], c[Maxq];
set <interv> S;
map <int, set <interv>::iterator> L, R;
int pos[Maxq], val[Maxq];
vector <int> un;
int BIT[Maxq];

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int Insert(int x, int val)
{
	for (int i = x; i < Maxq; i += i & -i)
		BIT[i] += val;
}

int main()
{
	scanf("%d %d", &n, &q);
	S.insert(interv(ii(0, 0), ii(n + 1, 0)));
	for (int i = 0; i < q; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) scanf("%d %d", &b[i], &c[i]);
		else if (L.count(a[i])) {
			interv v = *L[a[i]], u = *R[a[i]];
			pos[i] = v.r.first; val[i] = -1;
			S.erase(L[a[i]]); S.erase(R[a[i]]);
			L.erase(a[i]); R.erase(a[i]);
			R[v.l.second] = L[u.r.second] = S.insert(interv(v.l, u.r)).first;
		} else {
			interv z = *S.begin(); S.erase(S.begin());
			pos[i] = (z.l.first + z.r.first + 1) / 2; val[i] = 1;
			un.push_back(pos[i]);
			R[z.l.second] = L[a[i]] = S.insert(interv(z.l, ii(pos[i], a[i]))).first;
			R[a[i]] = L[z.r.second] = S.insert(interv(ii(pos[i], a[i]), z.r)).first;
		}
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < q; i++)
		if (a[i] == 0) {
			int r = upper_bound(un.begin(), un.end(), c[i]) - un.begin();
			int l = lower_bound(un.begin(), un.end(), b[i]) - un.begin();
			printf("%d\n", Get(r) - Get(l));
		} else {
			int ind = lower_bound(un.begin(), un.end(), pos[i]) - un.begin() + 1;
			Insert(ind, val[i]);
		}
	return 0;
}