#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

typedef long double ld;

const int Maxn = 2005;
const int Maxm = 5005;

int n;
int a[Maxn];
ld dist[Maxm];
ld mdist[Maxm];
ld res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			dist[abs(a[i] - a[j])] += 2.0l / ld(n * (n - 1));
	for (int i = Maxm - 1; i >= 0; i--)
		mdist[i] = dist[i] + mdist[i + 1];
	for (int i = 0; i < Maxm; i++)
		for (int j = 0; j < Maxm; j++) {
			int l = i + j + 1;
			if (l < Maxm) res += dist[i] * dist[j] * mdist[l];
		}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}