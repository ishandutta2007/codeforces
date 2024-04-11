#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, double> id;

const int Maxs = 100005;
const int Maxn = 5005;

struct pos {
	int mx;
	double prob[Maxn];
	pos(int mx = 0): mx(mx) {
		fill(prob + 1, prob + Maxn, 0.0); 
		prob[0] = 1.0;
	}
};

int n, q;
int a[Maxs];
vector <id> neigh[Maxs];
pos res;
double top;

void Apply(pos &P, double prob)
{
	for (int i = Maxn - 1; i > 0; i--)
		P.prob[i] = P.prob[i - 1] * prob + P.prob[i] * (1.0 - prob);
	P.prob[0] = P.prob[0] * (1.0 - prob);
}

void Add(pos &P, int val)
{
	if (val <= P.mx) return;
	if (val - Maxn >= P.mx) {
		P.mx = val;
		fill(P.prob + 1, P.prob + Maxn, 0.0);
		P.prob[0] = 1.0;
		return;
	}
	double sum = 0.0;
	for (int i = 0; i <= val - P.mx; i++)
		sum += P.prob[i];
	P.prob[0] = sum;
	for (int i = 1; i < Maxn; i++)
		P.prob[i] = val + i - P.mx < Maxn? P.prob[val + i - P.mx]: 0.0;
	P.mx = val;
}

void Join(pos &a, pos &b)
{
	double suma = 0.0, sumb = 0.0;
	for (int i = 0; i < a.mx - b.mx; i++)
		sumb += b.prob[i];
	for (int i = 0; i < Maxn; i++) {
		double proba = a.prob[i];
		double probb = a.mx + i - b.mx < Maxn? b.prob[a.mx + i - b.mx]: 0.0;
		a.prob[i] = proba * probb + proba * sumb + probb * suma;
		suma += proba; sumb += probb;
	}
}

void Union(pos &a, pos &b)
{
	if (a.mx - Maxn >= b.mx) return;
	if (b.mx - Maxn >= a.mx) { a = b; return; }
	if (a.mx >= b.mx) Join(a, b);
	else { Join(b, a); a = b; }
}

void Solve(int l, int r, pos &p)
{
	for (int i = l; i <= r; i++)
		if (!neigh[i].empty()) {
			id rp = neigh[i].back(); neigh[i].pop_back();
			pos P;
			Solve(i, rp.first, P);
			Apply(P, rp.second);
			Union(p, P);
			i = rp.first;
		} else Add(p, a[i]);
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (q--) {
		int l, r; double p; scanf("%d %d %lf", &l, &r, &p);
		neigh[l].push_back(id(r, p));
	}
	for (int i = 1; i <= n; i++)
		if (!neigh[i].empty()) sort(neigh[i].begin(), neigh[i].end());
	Solve(1, n, res);
	for (int i = 0; i < Maxn; i++)
		top += res.prob[i] * (res.mx + i);
	printf("%.9lf\n", top);
	return 0;
}