#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>


typedef long long ll;
typedef long double ld;

using namespace std;

const double PI = acos(-1);

typedef complex<double> clx;

int rev(int x, int k) {
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = (ans << 1) + (x & 1);
		x >>= 1;
	}
	return ans;
}

void fft(clx a[], int k, int inv) {
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		int x = rev(i, k);
		if (i < x)
			swap(a[i], a[x]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		for (int i = 0; i < n; i += bl * 2) {
			clx w = 1;
			double ang = PI / bl;
			if (inv)
				ang = -ang;
			clx wang(cos(ang), sin(ang));
			for (int j = 0; j < bl; ++j, w *= wang) {
				clx u = a[i + j];
				clx t = w * a[i + bl + j];
				a[i + j] = u + t;
				a[i + bl + j] = u - t;
			}
		}
	}
	if (inv)
		for (int i = 0; i < n; ++i)
			a[i] /= n;
}

const int MAXN = 1200000;


clx arr[MAXN * 2];



int n, m;
int a[MAXN];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[x] = 1, arr[x] = 1;
	}
	int go =  0;
	while ((1 << go) < 2 * m)
		++go;
	fft(arr, go, 0);
	for (int i = 0; i < (1 << go); ++i)
		arr[i] *= arr[i];
	fft(arr, go, 1); 
	vector<int> ans;
	for (int i = 1; i <= m; ++i) {
		int fl = abs(arr[i].real()) > 0.5;
		if (fl) {
			if (!a[i]) {
				cout << "NO\n";
				return 0;
			}
		}
		else {
			if (a[i])
				ans.push_back(i);
		}
	}
	printf("YES\n");
	printf("%d\n", (int)ans.size());
	for (int i: ans) {
		printf("%d ", i);
	}
	return 0;
}