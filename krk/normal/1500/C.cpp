#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1505;
const int Maxm = 26;
const int Maxb = 60;

map <vector <int>, vector <int> > M;
int n, m;
vector <int> A[Maxn];
vector <int> B[Maxn];
int a[Maxn];
ll fall[Maxn][Maxb], useful[Maxn][Maxb];
bool sep[Maxn];
ll gfall[Maxb], guseful[Maxb];
vector <int> res;

bool Solved()
{
	for (int i = 0; i + 1 < n; i++)
		if (!sep[i] && a[i] > a[i + 1])
			return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		A[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
		M[A[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		B[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	}
	for (int i = n - 1; i >= 0; i--) {
		auto it = M.find(B[i]);
		if (it == M.end() || it->second.empty()) {
			printf("-1\n"); return 0;
		}
		a[i] = it->second.back();
		it->second.pop_back();
	}
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j < m; j++) {
			if (B[i][j] > B[i + 1][j])
				fall[i][j / Maxb] |= 1ll << ll(j % Maxb);
			if (B[i][j] < B[i + 1][j])
				useful[i][j / Maxb] |= 1ll << ll(j % Maxb);
		}
	while (!Solved()) {
		fill(gfall, gfall + Maxb, 0ll);
		fill(guseful, guseful + Maxb, 0ll);
		for (int i = 0; i + 1 < n; i++) if (!sep[i])
			for (int j = 0; j < Maxb; j++) {
				gfall[j] |= fall[i][j];
				guseful[j] |= useful[i][j];
			}
		int got = -1;
		for (int j = 0; j < m; j++)
			if (bool(guseful[j / Maxb] & 1ll << ll(j % Maxb)) &&
				!bool(gfall[j / Maxb] & 1ll << ll(j % Maxb))) {
				got = j;
				break;
			}
		if (got == -1) { printf("-1\n"); return 0; }
		for (int i = 0; i + 1 < n; i++) if (!sep[i])
			if (B[i][got] < B[i + 1][got])
				sep[i] = true;
		res.push_back(got);
	}
	printf("%d\n", int(res.size()));
	for (int i = int(res.size()) - 1; i >= 0; i--)
		printf("%d%c", res[i] + 1, i - 1 >= 0? ' ': '\n');
    return 0;
}