#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
#define FFT_MAX 524288

#define MAXN 200005
const double PI = acos(-1);
// const int FFT_MAX = 524288;

void fft(cd* arr, int n, bool inv) {
	if (n == 1) return;
	cd even[n / 2], odd[n / 2];
	for (int i = 0; i * 2 < n; i++) {
		even[i] = arr[i * 2];
		odd[i] = arr[i * 2 + 1];
	}
	fft(even, n / 2, inv); fft(odd, n / 2, inv);
	double theta = 2 * PI / n * (inv ? -1 : 1);
	cd w(1), wn(cos(theta), sin(theta));
	for (int i = 0; i * 2 < n; i++) {
		arr[i] = even[i] + w * odd[i];
		arr[i + n / 2] = even[i] - w * odd[i];
		if (inv) {
			arr[i] /= 2;
			arr[i + n / 2] /= 2;
		}
		w *= wn;
	}
}
void mult(cd* arr1, cd* arr2) {
	fft(arr1, FFT_MAX, false); fft(arr2, FFT_MAX, false);
	for (int i = 0; i < FFT_MAX; i++) arr1[i] *= arr2[i];
	fft(arr1, FFT_MAX, true);
}

int n, x, y;
int a[MAXN];
cd fft1[FFT_MAX], fft2[FFT_MAX];
int q;
int ans[1000005];

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < FFT_MAX; i++) {
		fft1[i] = 0;
		fft2[i] = 0;
	}
	for (int i = 0; i <= n; i++) {
		fft1[a[i]] = 1;
		fft2[MAXN - a[i]] = 1;
	}
	mult(fft1, fft2);
	memset(ans, -1, sizeof ans);
	for (int i = MAXN + 1; i < FFT_MAX; i++) {
		if (round(fft1[i].real()) != 0) {
			int cur = (i - MAXN + y) * 2;
			for (int j = cur; j <= 1000000; j += cur) {
				ans[j] = cur;
			}
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l; scanf("%d", &l);
		printf("%d\n", ans[l]);
	}
	return 0;
}