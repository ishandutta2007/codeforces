#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxq = 100005;

int h, q;
int a[Maxq], b[Maxq], c[Maxq];
vector <int> E, L, R;

int GetE(int v) { return v != -1? E[v]: 0; }

void Create() { E.push_back(0); L.push_back(-1); R.push_back(-1); }

void Insert(int h, int v, int x, int val)
{
	if (h < 0) E[v] += val;
	else if (!(x & 1 << h)) { 
			E[v] -= GetE(L[v]);
			if (L[v] == -1) { Create(); L[v] = E.size() - 1; }
			Insert(h - 1, L[v], x, val);
			E[v] += GetE(L[v]);
		} else {
			E[v] -= GetE(R[v]);
			if (R[v] == -1) { Create(); R[v] = E.size() - 1; }
			Insert(h - 1, R[v], x, val);
			E[v] += GetE(R[v]);
		}
}

double Get(int v, int mx, double prob)
{
	if (v == -1) return prob * mx;
	int a = GetE(v), b = GetE(L[v]), c = GetE(R[v]);
	if (mx >= a + max(b, c)) return prob * mx;
	else if (b >= c)
			return prob * 0.5 * max(mx, a - c) + Get(L[v], max(mx, a - b), prob * 0.5);
		 else return prob * 0.5 * max(mx, a - b) + Get(R[v], max(mx, a - c), prob * 0.5);
}

int main()
{
	scanf("%d %d", &h, &q);
	Create();
	char s[15];
	while (q--) {
		int v, e; scanf("%s", s);
		if (s[0] == 'a') {
			scanf("%d %d", &v, &e);
			int mh = h;
			while (!(v & 1 << mh)) mh--;
			Insert(mh - 1, 0, v, e);
		} else printf("%.8lf\n", Get(0, 0, 1.0));
	}
	return 0;
}