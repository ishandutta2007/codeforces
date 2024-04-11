#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxb = 20;

int n, m;
bool has[Maxn];
int q;
int L[Maxn], R[Maxn];
vector <ii> seq;
vector <int> st[Maxb];
int my[Maxn];
char res[Maxn];

void Add(int t, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) st[t][v] ^= true;
	else {
		int m = l + r >> 1;
		if (a <= m) Add(t, 2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) Add(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
	}
}

bool Get(int t, int v, int l, int r, int x)
{
	bool res = st[t][v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res ^= Get(t, 2 * v, l, m, x);
		else res ^= Get(t, 2 * v + 1, m + 1, r, x);
	}
	return res;
}

int main()
{
	for (int i = 2; i < Maxb; i++)
		st[i].resize(1 << i + 2);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		has[a] ^= true;
	}
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &L[i], &R[i]);
		seq.push_back(ii(L[i] - 1, i));
		seq.push_back(ii(R[i], i));
	}
	sort(seq.begin(), seq.end());
	int i = 1;
	for (int j = 0; j < seq.size(); j++) {
		while (i <= seq[j].first) {
			if (has[i])
				for (int j = 2; j < Maxb && i - (1 << j - 2) >= 1; j++) {
					int lef = (i - (1 << j - 1) - (1 << j - 2) + 1 + (1 << j)) % (1 << j);
					int rig = (i - (1 << j - 2) + (1 << j)) % (1 << j);
					if (lef <= rig) Add(j, 1, 0, (1 << j) - 1, lef, rig);
					else {
						Add(j, 1, 0, (1 << j) - 1, lef, (1 << j) - 1);
						Add(j, 1, 0, (1 << j) - 1, 0, rig);
					}
				}
			i++;
		}
		int ind = seq[j].second;
		for (int j = 2; j < Maxb; j++)
			if (Get(j, 1, 0, (1 << j) - 1, L[ind] % (1 << j)))
				my[ind] ^= (1 << j - 1) - 1;
	}
	for (int i = 0; i < q; i++)
		res[i] = my[i]? 'A': 'B';
	res[q] = '\0';
	printf("%s\n", res);
    return 0;
}