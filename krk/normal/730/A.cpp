#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n;
int r[Maxn];
vector <vector <int> > res;

void Print(const vector <int> &V)
{
	string s(n, '0');
	for (int i = 0; i < V.size(); i++)
		s[V[i]] = '1';
	printf("%s\n", s.c_str());
}

bool Solve(int R)
{
	res.clear();
	priority_queue <ii> Q;
	for (int i = 0; i < n; i++)
		if (r[i] - R > 0)
			Q.push(ii(r[i] - R, i));
	while (!Q.empty()) {
		int v = Q.top().second, d = Q.top().first; Q.pop();
		if (Q.empty())
			if (d > 1) return false;
			else if (res.empty()) return false;
			else {
				bool was = false;
				for (int i = 0; i < res.back().size(); i++)
					was |= res.back()[i] == v;
				if (was) return false;
				else res.back().push_back(v);
			}
		else {
			int u = Q.top().second, z = Q.top().first; Q.pop();
			vector <int> tmp; tmp.push_back(v); tmp.push_back(u);
			res.push_back(tmp);
			if (--z > 0) Q.push(ii(z, u));
		}
		if (--d > 0) Q.push(ii(d, v));
	}
	return true;
}

void dumbSolve()
{
	res.clear();
	for (int i = 0; i + 1 < n; i++)
		while (r[i] > 0) {
			vector <int> tmp; tmp.push_back(i); tmp.push_back(i + 1);
			res.push_back(tmp);
			r[i]--;
			if (r[i + 1] > 0) r[i + 1]--;
		}
	while (r[n - 1] > 0) {
		vector <int> tmp; tmp.push_back(n - 1); tmp.push_back(n - 2);
		res.push_back(tmp);
		r[n - 1]--;
	}
}

int main()
{
	scanf("%d", &n);
	int mn = Maxn;
	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
		mn = min(r[i], mn);
	}
	bool solved = false;
	int R = 0;
	for (int i = mn; i > 0 && !solved; i--)
		if (Solve(i)) {
			R = i; solved = true;
		}
	if (!solved) dumbSolve();
	printf("%d\n", R);
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		Print(res[i]);
	return 0;
}