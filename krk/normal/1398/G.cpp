#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<ld> base;

const ld PI = acos(-1.0l);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		ld ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

const int Maxn = 1000005;

int n, x, y;
vector <int> A, B;
bool has[Maxn];
int res[Maxn];

void multiply (const vector<int> & a, const vector<int> & b) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	for (size_t i=0; i<n; ++i) {
        int sum = i - x;
        if (sum > 0 && sum <= x && int(fa[i].real() + 0.5) > 0)
            if (2 * sum + 2 * y < Maxn)
                has[2 * sum + 2 * y] = true;
	}
}

int main()
{
    scanf("%d %d %d", &n, &x, &y);
    A.resize(x + 1, 0);
    B.resize(x + 1, 0);
    for (int i = 0; i <= n; i++) {
        int a; scanf("%d", &a);
        A[a]++;
        B[x - a]++;
    }
    multiply(A, B);
    fill(res, res + Maxn, -1);
    for (int i = 1; i < Maxn; i++) if (has[i])
        for (int j = i; j < Maxn; j += i)
            res[j] = i;
    int q; scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a; scanf("%d", &a);
        printf("%d%c", res[a], i + 1 < q? ' ': '\n');
    }
    return 0;
}