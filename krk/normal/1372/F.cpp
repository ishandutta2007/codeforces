#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

map <int, int> M;

ii Ask(int l, int r)
{
	printf("? %d %d\n", l, r); fflush(stdout);
	int a, b; scanf("%d %d", &a, &b);
	return ii(a, b);
}

void Solve(int l, int r);

void Solve2(int l, int r, ii p)
{
	M[p.first] += p.second;
	if (r - l + 1 == p.second) return;
	vector <ii> lr;
	vector <ii> seq;
	for (int i = l; i <= r; i += p.second) {
		int to = min(r, i + p.second - 1);
		lr.push_back(ii(i, to));
		seq.push_back(Ask(i, to));
	}
	for (int i = 0; i < seq.size(); i++)
		if (seq[i].first == p.first)
			if (seq[i].second == p.second) lr[i].first = lr[i].second + 1;
			else if (lr[i].first > 1 && Ask(lr[i].first - 1, lr[i].first - 1).first == p.first) {
				lr[i].first += seq[i].second;
				lr[i - 1].second -= (p.second - seq[i].second);
			} else {
				lr[i].second -= seq[i].second;
				lr[i + 1].first += (p.second - seq[i].second);
				i++;
			}
	for (int i = 0; i < seq.size(); i++)
		if (lr[i].first <= lr[i].second)
			if (seq[i].first == p.first) Solve(lr[i].first, lr[i].second);
			else Solve2(lr[i].first, lr[i].second, seq[i]);
}

void Solve(int l, int r)
{
	Solve2(l, r, Ask(l, r));
}

int main()
{
	int n; scanf("%d", &n);
	Solve(1, n);
	printf("!");
	for (auto it: M)
		while (it.second--)
			printf(" %d", it.first);
	printf("\n");
	fflush(stdout);
    return 0;
}