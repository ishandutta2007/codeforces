#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000000;
const int Maxd = 36;

int a, b, w, h, n;
vector <int> seq;
map <ii, int> M;

ii Fix(ii ab)
{
	if (ab.first > ab.second) swap(ab.first, ab.second);
	return ab;
}

int Div(int a, int b)
{
	return a / b + (a % b != 0);
}

int main()
{
	scanf("%d %d %d %d %d", &a, &b, &w, &h, &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		seq.push_back(x);
	}
	sort(seq.rbegin(), seq.rend());
	while (seq.size() > Maxd) seq.pop_back();
	vector <ii> V;
	ii v1 = Fix(ii(Div(a, w), Div(b, h)));
	ii v2 = Fix(ii(Div(a, h), Div(b, w)));
	M[v1] = 0; M[v2] = 0;
	V.push_back(v1); V.push_back(v2);
	for (int i = 0; i < V.size(); i++) {
		ii v = V[i]; int d = M[v];
		if (v.first == 1 && v.second == 1) { printf("%d\n", d); return 0; }
		if (d >= seq.size()) continue;
		ii u1 = Fix(ii(Div(v.first, seq[d]), v.second));
		if (M.find(u1) == M.end()) { M[u1] = d + 1; V.push_back(u1); }
		ii u2 = Fix(ii(v.first, Div(v.second, seq[d])));
		if (M.find(u2) == M.end()) { M[u2] = d + 1; V.push_back(u2); }
	}
	printf("-1\n");
	return 0;
}