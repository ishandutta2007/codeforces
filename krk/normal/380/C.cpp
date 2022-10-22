#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 1000006;
const int Maxm = 4194304;
const int Maxq = 100005;

string s;
vector <int> cur;
vector <int> en[Maxm];
int pnt[Maxm];
int m;
iii q[Maxq];
int res[Maxq];

void Add(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) en[v].push_back(val);
	else {
		int m = l + r >> 1;
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int Get(int v, int l, int r, int x, int val)
{
	int res = 0;
	while (pnt[v] < en[v].size() && en[v][pnt[v]] <= val) pnt[v]++;
	res += pnt[v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res += Get(2 * v, l, m, x, val);
		else res += Get(2 * v + 1, m + 1, r, x, val);
	}
	return res;
}

int main()
{
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '(') cur.push_back(i);
		else if (!cur.empty()) { Add(1, 0, s.length() - 1, 0, cur.back(), i); cur.pop_back(); }
	cur.clear();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &q[i].first.second, &q[i].first.first); q[i].first.second--; q[i].first.first--;
		q[i].second = i;
	}
	sort(q, q + m);
	for (int i = 0; i < m; i++)
		res[q[i].second] = Get(1, 0, s.length() - 1, q[i].first.second, q[i].first.first);
	for (int i = 0; i < m; i++)
		printf("%d\n", 2 * res[i]);
	return 0;
}