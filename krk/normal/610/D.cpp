#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 2097152;

struct event {
	int x, y1, y2;
	bool er;
	event(int x = 0, int y1 = 0, int y2 = 0, bool er = false): x(x), y1(y1), y2(y2), er(er) {}
	bool operator <(const event &e) const {
		if (x != e.x) return x < e.x;
		if (y1 != e.y1) return y1 < e.y1;
		if (y2 != e.y2) return y2 < e.y2;
		return er < e.er;
	}
};

int n;
vector <event> E;
vector <int> un;
int fl[Maxm], tot[Maxm], sum[Maxm];
ll res;

int Get(int v, int l, int r, int sub = 0)
{
	if (tot[v] - sub) return un[r + 1] - un[l];
	else return sum[v];
}

void downOn(int v, int val)
{
	fl[v] += val; tot[v] += val;
}

void Down(int v, int l, int r)
{
	if (fl[v]) {
		downOn(2 * v, fl[v]); downOn(2 * v + 1, fl[v]);
		fl[v] = 0;
	}
}

void Union(int v, int l, int m, int r)
{
	tot[v] = min(tot[2 * v], tot[2 * v + 1]);
	sum[v] = Get(2 * v, l, m, tot[v]) + Get(2 * v + 1, m + 1, r, tot[v]);
}

void Update(int v, int l, int r, int a, int b, int delt)
{
	if (l == a && r == b) downOn(v, delt);
	else {
		Down(v, l, r);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
		Union(v, l, m, r);
	}
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int X1, Y1, X2, Y2; scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		if (X1 > X2) swap(X1, X2);
		if (Y1 > Y2) swap(Y1, Y2);
		if (X1 == X2) {
			un.push_back(Y1); un.push_back(Y2); un.push_back(Y2 + 1);
			E.push_back(event(X1, Y1, Y2, false)); 
			E.push_back(event(X2 + 1, Y1, Y2, true));
		} else {
			un.push_back(Y1); un.push_back(Y2 + 1);
			E.push_back(event(X1, Y1, Y1, false));
			E.push_back(event(X2 + 1, Y1, Y1, true));
		}
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	sort(E.begin(), E.end());
	int prv = -2000000000;
	for (int i = 0; i < E.size(); i++) {
		E[i].y1 = lower_bound(un.begin(), un.end(), E[i].y1) - un.begin();
		E[i].y2 = lower_bound(un.begin(), un.end(), E[i].y2) - un.begin();
		res += (ll(E[i].x) - ll(prv)) * ll(Get(1, 0, un.size() - 1)); prv = E[i].x;
		int mod = E[i].er? -1: 1;
		Update(1, 0, un.size() - 1, E[i].y1, E[i].y2, mod);
	}
	printf("%I64d\n", res);
	return 0;
}