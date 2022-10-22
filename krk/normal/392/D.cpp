#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000000;

struct triple {
	int a, b, c;
	triple(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
};

map <int, triple> M;
int n;
int a[Maxn], b[Maxn], c[Maxn];
set <ii> cur;
priority_queue <ii> Q;
int res = Inf;

void Insert(int a, int b)
{
	set <ii>::iterator it = cur.lower_bound(ii(a, b));
	if (it != cur.end() && b <= it->second) return;
	if (it != cur.end()) Q.push(ii(-(a + it->second), a));
	it = cur.insert(ii(a, b)).first;
	while (it != cur.begin()) {
		it--;
		if (it->second <= b) cur.erase(it++);
		else { it++; break; }
	}
	if (it != cur.begin()) {
		it--;
		Q.push(ii(-(it->first + b), it->first));
	}
}

bool Check(const ii &p)
{
	int cand = -p.first, i = p.second;
	set <ii>::iterator it = cur.lower_bound(ii(i, 0));
	if (it == cur.end() || it->first != i) return false;
	it++;
	if (it == cur.end() || it->second != cand - i) return false;
	return true;
}

int getBest()
{
	while (!Q.empty()) {
		ii v = Q.top();
		if (Check(v)) return -v.first;
		Q.pop();
	}
	return Inf;
}

int main()
{
	map <int, triple>::iterator it;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		it = M.find(a[i]);
		if (it == M.end()) M[a[i]] = triple(i + 1, Inf, Inf);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		it = M.find(b[i]);
		if (it == M.end()) M[b[i]] = triple(Inf, i + 1, Inf);
		else it->second.b = min(it->second.b, i + 1);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		it = M.find(c[i]);
		if (it == M.end()) M[c[i]] = triple(Inf, Inf, i + 1);
		else it->second.c = min(it->second.c, i + 1);
	}
	Insert(0, Inf); Insert(Inf, 0);
	for (it = M.begin(); it != M.end(); it++)
		if (it->second.a == Inf) Insert(it->second.b, it->second.c);
	for (int i = n; i >= 0; i--) {
		res = min(res, i + getBest());
		if (i) {
			it = M.find(a[i - 1]);
			if (it->second.a == i) Insert(it->second.b, it->second.c);
		}
	}
	printf("%d\n", res);
	return 0;
}