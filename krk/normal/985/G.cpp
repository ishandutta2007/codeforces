#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int Maxn = 200005;

int n, m;
ull ea[Maxn], eb[Maxn];
ull N;
ull A, B, C;
vector <int> neigh[Maxn];
ull res;

ull Count(ull l, ull r)
{
	return r - l + ull(1);
}

ull Sum(ull l, ull r)
{
	return (l + r) * Count(l, r) / ull(2);
}

ull Solve(ull a, ull b)
{
	int lef = lower_bound(neigh[a].begin(), neigh[a].end(), a) - neigh[a].begin();
	int rig = lower_bound(neigh[b].begin(), neigh[b].end(), b) - neigh[b].begin();
	ull res = 0;
	while (lef < neigh[a].size() && rig < neigh[b].size())
		if (neigh[a][lef] < neigh[b][rig]) lef = lower_bound(neigh[a].begin() + lef, neigh[a].end(), neigh[b][rig]) - neigh[a].begin();
		else if (neigh[a][lef] > neigh[b][rig]) rig = lower_bound(neigh[b].begin() + rig, neigh[b].end(), neigh[a][lef]) - neigh[b].begin();
		else {
			res += A * a + B * b + C * neigh[a][lef];
			lef++; rig++;
		}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	cin >> A >> B >> C;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
		ea[i] = a; eb[i] = b;
		if (ea[i] > eb[i]) swap(ea[i], eb[i]);
	}
	N = n;
	for (ull i = 0; i < n; i++) {
		if (i + 2 < N) 
			res += (N - i - 1) * (N - i - 2) / ull(2) * i * A;
		res += i * (N - i - 1) * i * B;
		if (i >= 2)
			res += i * (i - 1) / ull(2) * i * C;
	}
	for (int i = 0; i < m; i++) {
		if (ea[i] > 0) res -= Count(0, ea[i] - 1) * (B * ea[i] + C * eb[i]) + A * Sum(0, ea[i] - 1);
		if (ea[i] + 1 < eb[i]) res -= Count(ea[i] + 1, eb[i] - 1) * (A * ea[i] + C * eb[i]) + B * Sum(ea[i] + 1, eb[i] - 1);
		if (eb[i] < N - 1) res -= Count(eb[i] + 1, N - 1) * (A * ea[i] + B * eb[i]) + C * Sum(eb[i] + 1, N - 1);
	}
	for (ull i = 0; i < n; i++) {
		sort(neigh[i].begin(), neigh[i].end());
		vector <ull> VA, VB;
		for (int j = 0; j < neigh[i].size(); j++) {
			ull u = neigh[i][j];
			if (u < i) VA.push_back(u);
			else VB.push_back(u);
		}
		ull sumA = 0, sumB = 0;
		for (ull j = 0; j < VA.size(); j++) {
			res += j * (B * VA[j] + C * i) + A * sumA;
			sumA += VA[j];
		}
		if (!VB.empty())
			for (ull j = ull(VB.size()); j > 0; j--) {
				res += (ull(VB.size()) - ull(1) - (j - 1)) * (A * i + B * VB[j - 1]) + C * sumB;
				sumB += VB[j - 1];
			}
		res += ull(VA.size()) * ull(VB.size()) * i * B + ull(VB.size()) * sumA * A + ull(VA.size()) * sumB * C;
	}
	for (int i = 0; i < m; i++)
		res -= Solve(ea[i], eb[i]);
	cout << res << endl;
	return 0;
}