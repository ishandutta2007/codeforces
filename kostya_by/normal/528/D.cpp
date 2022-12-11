#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200200;
const double PI = acos(-1.0);

struct complex {
	double re, im;
	complex(double re = 0.0, double im = 0.0) : re(re), im(im) {};
};

complex operator+(const complex& a, const complex& b) {
	return complex(a.re + b.re, a.im + b.im);
}

complex operator-(const complex& a, const complex& b) {
	return complex(a.re - b.re, a.im - b.im);
}

complex operator*(const complex& a, const complex& b) {
	return complex(a.re * b.re - a.im * b.im, 
		a.re * b.im + a.im * b.re);
}

complex operator/(const complex& a, const double& b) {
	return complex(a.re / b, a.im / b);
}

void fft(vector<complex>& a, bool invert) {
	int n = (int)a.size();
	if (n == 1) {
		return;
	}
	vector<complex> a0(n / 2);
	vector<complex> a1(n / 2);
	for (int i = 0; i < n; i += 2) {
		a0[i / 2] = a[i];
		a1[i / 2] = a[i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double alpha = (invert ? -2.0 : 2.0) * PI / n;
	complex wk = 1.0;
	complex w1 = complex(cos(alpha), sin(alpha));

	for (int k = 0; k < n / 2; k++) {
		a[k] = a0[k] + wk * a1[k];
		a[n / 2 + k] = a0[k] - wk * a1[k];
		if (invert) {
			a[k] = a[k] / 2.0;
			a[n / 2 + k] = a[n / 2 + k] / 2.0;
		}
		wk = wk * w1;
	}

}

void multiply(const vector<int> &a, const vector<int> &b, vector<int>& result) {

	// for (int x : a) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	// for (int x : b) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	vector<complex> fa(a.begin(), a.end());
	vector<complex> fb(b.begin(), b.end());
	int n = 1;
	while ( n < (int)max(a.size(), b.size()) ) {
		n *= 2;
	}
	// n *= 2;
	fa.resize(n);
	fb.resize(n);
	result.resize(n);
	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++) {
		fa[i] = fa[i] * fb[i];
	}
	fft(fa, true);
	for (int i = 0; i < n; i++) {
		result[i] = (int)(fa[i].re + 0.5);
	}

	// for (int x : result) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

}

int n, m, k;
char s[MAXN];
char t[MAXN];
int pref[MAXN];
int number_of_matches[MAXN];

void process(char ch) {
	memset(pref, 0, sizeof(pref));

	for (int i = 0; i < n; i++) {
		if (s[i] != ch) {
			continue;
		}
		int left = max(i - k, 0);
		int right = min(i + k + 1, n);
		pref[left] += 1;
		pref[right] -= 1;
	}

	vector<int> a(n);
	vector<int> b(m);

	int s = 0;
	for (int i = 0; i < n; i++) {
		s += pref[i];
		if (s) {
			a[i] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		b[i] = (t[i] == ch);
	}

	vector<int> result;
	multiply(a, b, result);

	for (int i = 0; i < n; i++) {
		number_of_matches[i] += result[i];
	}

}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s);
	scanf("%s", t); 
	reverse(t, t + m);
	process('A');
	process('T');
	process('G');
	process('C');

	int answer = 0;
	for (int i = m - 1; i < n; i++) {
		if (number_of_matches[i] == m) {
			answer += 1;
		}
		// cerr << number_of_matches[i] << " ";
	}

	printf("%d\n", answer);

}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}