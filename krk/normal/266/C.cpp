#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
int x[Maxn], y[Maxn];
int rows[Maxn], rrow[Maxn];
bool tk[Maxn];
vector <int> res1, res2, res3;

void Swap(int c1, int c2)
{
	for (int i = 0; i < n - 1; i++)
		if (y[i] == c1) y[i] = c2;
		else if (y[i] == c2) y[i] = c1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &x[i], &y[i]);
		rows[x[i]]++;
	}
	for (int i = 1; i <= n; i++) rrow[i] = i;
	for (int i = 1; i <= n; i++) {
		int bj = i;
		for (int j = i + 1; j <= n; j++)
			if (rows[j] < rows[bj]) bj = j;
		if (i != bj) { res1.push_back(1); res2.push_back(i); res3.push_back(bj); swap(rows[i], rows[bj]); swap(rrow[i], rrow[bj]); }
	}
	int fir = 1;
	for (int i = 1; i <= n; i++) {
		vector <int> cols;
		for (int j = 0; j < n - 1; j++)
			if (x[j] == rrow[i]) cols.push_back(y[j]);
		sort(cols.begin(), cols.end());
		for (int j = 0; j < cols.size(); j++)
			if (cols[j] < i) tk[cols[j]] = true;
			else {
				while (tk[fir]) fir++;
				res1.push_back(2); res2.push_back(fir); res3.push_back(cols[j]);
				Swap(fir, cols[j]); tk[fir] = true;
			}
	}
	printf("%d\n", res1.size());
	for (int i = 0; i < res1.size(); i++)
		printf("%d %d %d\n", res1[i], res2[i], res3[i]);
	return 0;
}