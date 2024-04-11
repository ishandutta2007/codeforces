#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int maxN = 1005;
int n, k;
int a[maxN];

struct base {
    double re, im;
    double real() const { return re; }
    double imag() const { return im; }
    base() {}
    base(double re): re(re), im(0) {}
    base(double re, double im): re(re), im(im) {}
    base operator * (const base &rhs) {
        return base(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
    }
    base operator + (const base &rhs) {
        return base(re + rhs.re, im + rhs.im);
    }
    base operator - (const base &rhs) {
        return base(re - rhs.re, im - rhs.im);
    }
    void operator /= (const double d) {
        re /= d; im /= d;
    }
};

vector < base > q((1 << 20));
vector < base > qq((1 << 20));
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * (pi) /len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			base w (1);
			for (int j=0; j < len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i + j + len/2] = u - v;
				w = w * wlen;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; ++i)
			a[i] /= n;
}
vector < base > mult(vector < base > p, vector < base > t, bool sq) {
    if (sq) {
        fft(p, false);
        for (int i = 0; i < p.size(); i++) p[i] = p[i] * p[i];
        fft(p, true);
    }
    else {
        fft(p, false);
        for (int i = 0; i < p.size(); i++) p[i] = p[i] * p[i] * q[i];
        fft(p, true);
    }
    for (int i = 0; i < p.size(); i++) {
        if (p[i].real() > 0.5) {
            p[i] = 1;
        }
        else p[i] = 0;
    }
    return p;
}
vector < base > pw(vector < base > p, int k) {
    if (k == 1) return p;
    vector < base > to = pw(p, k / 2);
    if ((k & 1) == 0) return mult(to, to, true);
    else return mult(to, p, false);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q[a[i]] = 1;
        qq[a[i]] = 1;
    }
    fft(q, false);
    vector < base > p = pw(qq, k);
    for (int i = 1; i < (1 << 20); i++) {
        if (p[i].real() > 0.5) cout << i << " ";
    }
    return 0;
}