#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 10005;

int T;
int m, k;
vector <ii> seq;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &m, &k);
		seq.clear();
		for (int i = 1; i <= k; i++) {
			int a; scanf("%d", &a);
			if (a) seq.push_back(ii(a, i));
		}
		sort(seq.rbegin(), seq.rend());
		int lef = 1, rig = Maxn - 1;
		while (lef <= rig) {
			int n = lef + rig >> 1;
			int neutr = ((n + 1) / 2) * ((n + 1) / 2);
			int pos = ((n + 1) / 2) * (n / 2);
			if (m <= neutr + 2 * pos && seq[0].first <= pos + neutr)
				rig = n - 1;
			else lef = n + 1;
		}
		int n = lef;
		int neutr = ((n + 1) / 2) * ((n + 1) / 2);
		int pos = ((n + 1) / 2) * (n / 2);
		vector <int> A, B, C;
		int lftA = neutr;
		int lftB = pos;
		int lftC = pos;
		for (int i = 0; i < seq.size(); i++)
			while (seq[i].first--)
				if (lftB > 0) { B.push_back(seq[i].second); lftB--; }
				else if (lftA > 0) { A.push_back(seq[i].second); lftA--; }
				else { C.push_back(seq[i].second); lftC--; }
		printf("%d\n", n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int res = 0;
				if (i % 2 == 0 && j % 2 == 0) {
					if (!A.empty()) { res = A.back(); A.pop_back(); }
				} else if (i % 2 == 0 && j % 2 == 1) {
					if (!B.empty()) { res = B.back(); B.pop_back(); }
				} else if (i % 2 == 1 && j % 2 == 0) {
					if (!C.empty()) { res = C.back(); C.pop_back(); }
				}
				printf("%d%c", res, j + 1 < n? ' ': '\n');
			}
	}
    return 0;
}