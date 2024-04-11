#include <cstdio>
#include <set>
using namespace std;

typedef long double ld;
typedef pair <ld, int> ldi;

const int Maxn = 200005;

int n, t, q;
int p[Maxn];
int l[Maxn];
int h[Maxn];
ld valA[Maxn], valB[Maxn];
set <ldi> qA, qB;
ld res;

ld getA(int x) { return ld(p[x]) * (ld(h[x] - 1) / (l[x] - 1) - ld(h[x]) / l[x]); }

ld getB(int x) { return ld(p[x]) * (ld(h[x] + 1) / (l[x] + 1) - ld(h[x]) / l[x]); }

void Remove(int x)
{
	if (h[x] > 0) qA.erase(ldi(getA(x), -x));
	if (2 * h[x] < l[x]) qB.erase(ldi(getB(x), x));
}

void Insert(int x)
{
	if (h[x] > 0) qA.insert(ldi(getA(x), -x));
	if (2 * h[x] < l[x]) qB.insert(ldi(getB(x), x));
}

void addMe(int x)
{
	res += getB(x);
	Remove(x);
	h[x]++; l[x]++; t--;
	Insert(x);
}

void remMe(int x)
{
	res += getA(x);
	Remove(x);
	h[x]--; l[x]--; t++;
	Insert(x);
}

void Add(int x)
{
	res -= ld(p[x]) * ld(h[x]) / l[x]; 
	Remove(x);
	l[x]++;
	Insert(x);
	res += ld(p[x]) * ld(h[x]) / l[x]; 
}

void Rem(int x)
{
	if (2 * h[x] > l[x] - 1)
		remMe(x);
	res -= ld(p[x]) * ld(h[x]) / l[x]; 
	Remove(x);
	l[x]--;
	Insert(x);
	res += ld(p[x]) * ld(h[x]) / l[x]; 
}

int main()
{
	scanf("%d %d %d", &n, &t, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &l[i]);
		Insert(i);
	}
	while (t && !qB.empty())
		addMe(qB.rbegin()->second);
	while (q--) {
		int typ, r; scanf("%d %d", &typ, &r);
		if (typ == 1) Add(r);
		else if (typ == 2) Rem(r);
		while (!qA.empty() && !qB.empty() && qA.rbegin()->first + qB.rbegin()->first > 0) {
			int a = -qA.rbegin()->second, b = qB.rbegin()->second;
			if (a == b) break;
			remMe(a); addMe(b);
		}
		while (t && !qB.empty())
			addMe(qB.rbegin()->second);
		printf("%.10lf\n", double(res));
	}
	return 0;
}