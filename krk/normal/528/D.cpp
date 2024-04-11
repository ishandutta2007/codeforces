#include <cstdio>
#include <string>
#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex <double> base;

const double pi = acos(-1.0);
const int Maxn = 200005;
const int Inf = 1000000000;
const int Maxd = 4;
const string lets = "ATGC";

int slen, tlen, k;
char S[Maxn], T[Maxn];
int L[Maxn][Maxd], R[Maxn][Maxd];
bool ok[Maxn][Maxd];
int A[Maxn], B[Maxn];
bool nres[Maxn];
int tres;

void Change(vector <base> &a, bool invert = false)
{
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int b = n >> 1;
		for (; j >= b; b >>= 1) j -= b;
		j += b;
		if (i < j) swap(a[i], a[j]);
	}
	for (int l = 2; l <= n; l <<= 1) {
		double ang = 2 * pi / l * (invert? -1: 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += l) {
			base w(1);
			for (int j = 0; j < l / 2; j++) {
				base u = a[i + j], v = a[i + j + l / 2] * w;
				a[i + j] = u + v;
				a[i + j + l / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; i++)
			a[i] /= n;
}

void solvePart()
{
	vector <base> fa(A, A + tlen), fb(B, B + slen);
	int n = 1;
	while (n < tlen || n < slen) n <<= 1;
 	n <<= 1;
 	fa.resize(n); fb.resize(n);
 	Change(fa); Change(fb);
 	for (int i = 0; i < n; i++)
 		fa[i] *= fb[i];
 	Change(fa, true);
 	for (int i = 0; i < slen; i++)
 		nres[i] |= int(fa[i + tlen - 1].real() + 0.5) > 0;
}

void Solve(int id)
{
	for (int i = 0; i < tlen; i++)
		A[i] = T[tlen - 1 - i] == lets[id];
	for (int i = 0; i < slen; i++)
		B[i] = !ok[i][id];
	solvePart();
}

int main()
{
	scanf("%d %d %d", &slen, &tlen, &k);
	scanf("%s", S); scanf("%s", T);

	for (int i = 0; i < slen; i++) {
		for (int j = 0; j < Maxd; j++)
			L[i][j] = i? L[i - 1][j]: -Inf;
		L[i][lets.find(S[i])] = i;
	}
	for (int i = slen - 1; i >= 0; i--) {
		for (int j = 0; j < Maxd; j++)
			R[i][j] = i + 1 < slen? R[i + 1][j]: Inf;
		R[i][lets.find(S[i])] = i;
	}
	for (int i = 0; i < slen; i++)
		for (int j = 0; j < Maxd; j++)
			ok[i][j] = min(i - L[i][j], R[i][j] - i) <= k;

	for (int i = 0; i < Maxd; i++)
		Solve(i);
	for (int i = 0; i + tlen <= slen; i++)
		tres += !nres[i];
	printf("%d\n", tres);
	return 0;
}