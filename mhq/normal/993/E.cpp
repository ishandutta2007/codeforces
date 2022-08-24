#include <bits/stdc++.h>
using namespace std;
typedef complex<double> base;
const int maxN = 2 * (int)1e5 + 10;
const double PI = acos(-1.0);
int n, x;
bool f[maxN];
long long ans[maxN];
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
void go(vector < int >& a, vector < int >& b) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	int k = 1;
	while (k < max (a.size(), b.size()))  k <<= 1;
	k <<= 1;
	fa.resize (k),  fb.resize (k);

	fft (fa, false),  fft (fb, false);
	for (int  i=0; i<k; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

    for (int i = 0; i < fa.size(); i++) {
        if (i > n) break;
        ans[i] += (long long)(fa[i].real() + 0.5);
    }
}
void solve(int l, int r) {
    if (r - l + 1 <= 2) {
        for (int i1 = l; i1 <= r; i1++) {
            for (int i2 = i1; i2 <= r; i2++) {
                int sum = 0;
                for (int k = i1; k <= i2; k++) {
                    sum += (f[k] == true);
                }
                ans[sum]++;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid - 1);
    solve(mid + 1, r);
    vector < int > a(mid - l + 2, 0);
    vector < int > b(r - mid + 2, 0);
    int sum = 0;
    for (int i = mid; i >= l; i--) {
        if (f[i] == true) sum++;
        a[sum]++;
    }
    sum = 0;
    b[0]++;
    for (int j = mid + 1; j <= r; j++) {
        if (f[j] == true) sum++;
        b[sum]++;
    }
    go(a, b);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (x > t) f[i] = true;
        else f[i] = false;
    }
    solve(1, n);
    for (int i = 0; i <= n; i++) cout << ans[i] << " ";
    return 0;
}