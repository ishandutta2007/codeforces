#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <complex>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 500005;
const int Maxm = 2000005;
const ld PI = acos(-1.0l);

char tmp[Maxn];
int t;
int n;
string s;
bool pos[Maxn];

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

typedef complex<double> base;

int rev[Maxm];
base wlen_pw[Maxm];
 
void fft (base a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			base t,
				*pu = a+i,
				*pv = a+i+len2, 
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu += t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	size_t n = 1; int cnt = 0;
	while (n < max (a.size(), b.size()))  { n <<= 1; cnt++; }
	n <<= 1; cnt++;
	calc_rev(n, cnt);
	base *fa = new base[n];
	base *fb = new base[n];
	for (int i = 0; i < a.size(); i++)
		fa[i] = a[i];
	for (int i = a.size(); i < n; i++)
		fa[i] = 0;
	for (int i = 0; i < b.size(); i++)
		fb[i] = b[i];
	for (int i = b.size(); i < n; i++)
		fb[i] = 0;
 
	fft (fa, n, false),  fft (fb, n, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, n, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
	delete [] fa; delete [] fb;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n); Read(s);
		vector <int> A(n, 0), B(n, 0);
		for (int i = 0; i < n; i++)
			if (s[i] == 'K') A[i] = 1;
			else if (s[i] == 'V') B[-i + n - 1] = 1;
		vector <int> C; multiply(A, B, C);
		vector <int> res;
		fill(pos, pos + n + 1, true);
		for (int i = 0; i < C.size(); i++) if (C[i] != 0) {
			int ind = abs(i - (n - 1));
			pos[ind] = false;
		}
		int cnt = 1;
		for (int i = n - 1; i >= 1; i--) {
			for (int j = i + i; j <= n && pos[i]; j += i)
				pos[i] = pos[j];
			cnt += pos[i];
		}
		printf("%d\n", cnt);
		bool pr = false;
		for (int i = 1; i <= n; i++)
			if (pos[i]) {
				if (pr) printf(" ");
				else pr = true;
				printf("%d", i);
			}
		printf("\n");
	}
	return 0;
}