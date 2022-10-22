#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
typedef long double ld;
typedef long long ll;

const double PI = acos(-1.0l);
const int MAXN = 524288;
const int Maxb = 19;
const int Maxp = 450;

int rev[MAXN];
base wlen_pw[MAXN];
int n, X;
int a[MAXN];
int sum[MAXN];
int cnt[MAXN];
base A[MAXN], B[MAXN];
int C[MAXN];
ll res[MAXN];
 
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

void Multiply(base A[], base B[], int C[])
{
	fft(A, MAXN, false); fft(B, MAXN, false);
	for (int i = 0; i < MAXN; i++)
		A[i] *= B[i];
	fft(A, MAXN, true);
	for (int i = 1; i <= n; i++)
		C[i] = int(A[n + i].real() + 0.5);
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}

void Solve(bool big1, bool big2)
{
	for (int i = 0; i < MAXN; i++) {
		A[i] = big1? cnt[i] / Maxp: cnt[i] % Maxp;
		B[i] = 0;
	}
	for (int i = 0; i <= n; i++)
		B[i] = big2? cnt[n - i] / Maxp: cnt[n - i] % Maxp;
	Multiply(A, B, C);
	for (int i = 1; i <= n; i++) {
		ll add = C[i];
		if (big1) add *= Maxp;
		if (big2) add *= Maxp;
		res[i] += add;
	}
}

int main()
{
	calc_rev(MAXN, Maxb);
	scanf("%d %d", &n, &X);
	sum[0] = 0; cnt[0]++;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + (a[i] < X);
		cnt[sum[i]]++;
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			Solve(i, j);
	int cur = 0;
	while (cur <= n) {
		int ot = cur + 1;
		while (ot <= n && sum[cur] == sum[ot])
			ot++;
		int has = ot - cur;
		res[0] += ll(has) * (has - 1) / 2;
		cur = ot;
	}
	for (int i = 0; i <= n; i++)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}