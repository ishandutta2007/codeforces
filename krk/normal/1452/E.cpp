#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 2005;

int n, m, k;
int R[Maxn][Maxn], C[Maxn][Maxn];
int mx;

void Add(int R[][Maxn], int lef, int rig, int flef, int frig, int val)
{
	for (int i = lef; i <= rig; i++) {
		R[i][1] += val;
		R[i][flef] -= val;
		R[i][frig + 1] += val;
		R[i][n + 1] -= val;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		vector <iii> seq;
		int a, b; scanf("%d %d", &a, &b);
		for (int i = 1; i <= n; i++) {
			int lef = max(a, i), rig = min(b, i + k - 1);
			int my = max(0, rig - lef + 1);
			if (seq.empty() || seq.back().first != my)
				seq.push_back(iii(my, ii(i, i)));
			else seq.back().second.second = i;
		}
		sort(seq.rbegin(), seq.rend());
		Add(R, seq[0].second.first, seq[0].second.second, n + 1, n + 1, seq[0].first);
		int flef = seq[0].second.first, frig = seq[0].second.second;
		Add(C, seq[0].second.first, seq[0].second.second, flef, frig, seq[0].first);
		for (int i = 1; i < seq.size(); i++) {
			Add(R, seq[i].second.first, seq[i].second.second, flef, frig, seq[i].first);
			flef = min(flef, seq[i].second.first);
			frig = max(frig, seq[i].second.second);
			Add(C, seq[i].second.first, seq[i].second.second, flef, frig, seq[i].first);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			R[i][j] += R[i][j - 1];
			C[j][i] += C[j][i - 1];
			mx = max(mx, R[i][j] + C[j][i]);
		}
	printf("%d\n", mx);
    return 0;
}