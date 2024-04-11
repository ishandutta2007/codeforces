#include <bits/stdc++.h>
using namespace std;

typedef double ld;
typedef pair <ld, int> ldi;

const int Maxn = 1005;

int n;
ld p[Maxn][Maxn];
ld res[Maxn];
ldi seq[Maxn];
bool tk[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int prob; scanf("%d", &prob);
			p[i][j] = prob / 100.0l;
		}
	fill(res + 1, res + n, 1); res[n] = 0;
	vector <ldi> seq; seq.push_back(ldi(0, n));
	tk[n] = true;
	while (!tk[1]) {
		ldi best = ldi(1e10, 0);
		for (int i = 1; i < n; i++) if (!tk[i]) {
			ld cand = 1;
			ld prob = 1;
			for (int j = 0; j < seq.size() && prob > 0; j++) if (p[i][seq[j].second] > 0) {
				cand += prob * p[i][seq[j].second] * seq[j].first;
				prob *= (ld(1.0) - p[i][seq[j].second]);
			}
			if (prob > 0) cand /= (ld(1.0) - prob);
			if (cand < best.first) best = ldi(cand, i);
		}
		seq.push_back(best);
		res[best.second] = best.first;
		tk[best.second] = true;
	}
	cout << fixed << setprecision(10) << res[1] << endl;
    return 0;
}