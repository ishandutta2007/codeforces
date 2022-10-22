#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
int n;
int B[Maxn][Maxn];
int res[Maxn];

bool Has(int a, int b)
{
	if (B[a][b] != 0) return B[a][b] > 0;
	printf("1 %d %d\n", a, b); fflush(stdout);
	int res; scanf("%d", &res);
	if (res == 1) {
		B[a][b] = 1;
		B[b][a] = -1;
	} else {
		B[a][b] = -1;
		B[b][a] = 1;
	}
	return res;
}

bool Any(int v, const vector <int> &V)
{
	printf("2 %d %d", v, int(V.size()));
	for (int i = 0; i < V.size(); i++)
		printf(" %d", V[i]);
	printf("\n"); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

vector <int> Get(int l, int r)
{
	vector <int> res;
	if (l == r)
		res.push_back(l);
	else {
		int m = l + r >> 1;
		auto A = Get(l, m);
		auto B = Get(m + 1, r);
		int i = 0, j = 0;
		while (i < A.size() || j < B.size())
			if (i < A.size() && (j >= B.size() || Has(A[i], B[j])))
				res.push_back(A[i++]);
			else res.push_back(B[j++]);
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			fill(B[i], B[i] + n, 0);
		auto seq = Get(0, n - 1);
		int col = 0;
		while (!seq.empty()) {
			int v = seq.back(); seq.pop_back();
			vector <int> my; my.push_back(v);
			for (int i = 0; i < my.size(); i++)
				while (!seq.empty() && Any(my[i], seq))
					while (true) {
						int u = seq.back(); seq.pop_back();
						my.push_back(u);
						if (Has(my[i], u)) break;
					}
			for (int i = 0; i < my.size(); i++)
				res[my[i]] = col;
			col++;
		}
		printf("3\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%d", int(res[i] >= res[j]));
			printf("\n");
		}
		fflush(stdout);
		int dum; scanf("%d", &dum);
	}
    return 0;
}