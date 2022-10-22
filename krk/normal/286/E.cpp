#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<double> base;

const ld PI = acos(-1.0l);
const int MAXN = 1 << 22;

int n, m;
vector <int> seq, got;
int rev[MAXN];
base wlen_pw[MAXN];
vector <int> res;
 
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
		double ang = 2*PI/len * (invert ? -1 : 1);
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

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

int main()
{
	scanf("%d %d", &n, &m);
	seq.resize(m + 1);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		seq[a] = 1;
	}
	multiply(seq, seq, got);
	for (int i = 1; i <= m; i++)
		if (seq[i] > 0 && got[i] == 0) res.push_back(i);
		else if (seq[i] == 0 && got[i] > 0) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}