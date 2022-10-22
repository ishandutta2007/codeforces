#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef pair <double, int> di;

const int Maxn = 3005;
const int Maxm = Maxn * Maxn / 2;
const int Maxb = 64;
const int Maxp = Maxn / Maxb + 1;

int n;
int x[Maxn], y[Maxn];
int m;
int a[Maxm], b[Maxm];
di srt[Maxm];
ull my[Maxn][Maxp];

bool Test(int a, int b)
{
	for (int i = 0; i < Maxp; i++)
		if (my[a][i] & my[b][i]) return true;
	return false;
}

void Add(int a, int b)
{
	my[a][b / Maxb] |= ull(1) << b % Maxb;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		for (int j = 0; j < i; j++) {
			a[m] = j; b[m] = i;
			srt[m] = di(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), m); m++;
		}
	}
	sort(srt, srt + m);
	for (int i = m - 1; i >= 0; i--) {
		int A = a[srt[i].second], B = b[srt[i].second];
		if (Test(A, B)) {
			printf("%.10lf\n", srt[i].first / 2.0); break;
		}
		Add(A, B); Add(B, A);
	}
	return 0;
}