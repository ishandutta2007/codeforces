#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n, a, b, c, d, start, len;
int t[Maxn], q[Maxn];
ll my[Maxn];
ll cur;
map <ll, int> M;
ll mod;

void Add(ll x) { M[x]++; }

void Rem(ll x)
{
	if (--M[x] == 0) M.erase(x);
}

ll Get()
{
	if (M.empty()) return cur;
	return M.begin()->first + mod;
}

bool Ok()
{
	return cur >= 0 && Get() >= 0;
}

int main()
{
	scanf("%d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &start, &len);
	vector <int> seq;
	seq.push_back(0);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &q[i]);
		seq.push_back(t[i]);
		seq.push_back(t[i] + 1);
		if (t[i] >= len) seq.push_back(t[i] - len);
		if (t[i] >= len - 1) seq.push_back(t[i] - len + 1);
	}
	sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
	cur = start;
	mod = 0;
	ll sum = 0;
	int p2 = 0, p1 = 0;
	for (int i = 0; i < seq.size(); i++) {
		while (p2 < n && seq[i] + len > t[p2]) {
			sum += q[p2]? c: -d;
			my[p2] = cur + sum - mod;
			Add(cur + sum - mod);
			p2++;
		}
		while (p1 < n && t[p1] < seq[i]) {
			Rem(my[p1]); 
			cur += q[p1]? a: -b;
			sum -= q[p1]? c: -d;
			mod += q[p1]? (a - c): -(b - d);
			p1++;
		}
		if (Ok()) { printf("%d\n", seq[i]); return 0; }
		if (cur < 0) break;
	}
	printf("-1\n");
	return 0;
}