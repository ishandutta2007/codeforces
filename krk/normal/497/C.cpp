#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

struct pos {
	int l, r;
	int ind;
	pos(int l = 0, int r = 0, int ind = 0):
		l(l), r(r), ind(ind) {}
	bool operator <(const pos &b) const {
		if (l != b.l) return l < b.l;
		if (r != b.r) return r < b.r;
		return ind < b.ind;
	}
};

int n;
pos P[Maxn];
int m;
int R[Maxn];
pos A[Maxn];
int k[Maxn];
vector <ii> seq;
set <ii> S;
int res[Maxn];

void Take(int p, int a)
{
	res[p] = a;
	k[a]--;
	if (k[a] == 0) S.erase(ii(R[a], a));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &P[i].l, &P[i].r);
		P[i].ind = i;
	}
	sort(P + 1, P + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &A[i].l, &A[i].r);
		A[i].ind = i;
		R[i] = A[i].r;
		scanf("%d", &k[i]);
	}
	sort(A + 1, A + m + 1);
	for (int i = 1; i <= m; i++) {
		seq.push_back(ii(A[i].l, A[i].ind));
		seq.push_back(ii(A[i].r + 1, -A[i].ind));
	}
	sort(seq.begin(), seq.end());
	int pnt = 0;
	for (int i = 1; i <= n; i++) {
		while (pnt < seq.size() && seq[pnt].first <= P[i].l) {
			if (seq[pnt].second > 0) S.insert(ii(R[seq[pnt].second], seq[pnt].second));
			else S.erase(ii(R[-seq[pnt].second], -seq[pnt].second));
			pnt++;
		}
		set <ii>::iterator it = S.lower_bound(ii(P[i].r, 0));
		if (it == S.end()) { printf("NO\n"); return 0; }
		else Take(P[i].ind, it->second);
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}