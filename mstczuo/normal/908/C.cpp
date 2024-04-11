# include <bits/stdc++.h>
using namespace std;

int n, r;
int x[1200];
int mask[1200];

double y[1200];

double calc(double x) {
	return sqrt(4. * r * r - x * x);
}

int main() {
	scanf("%d%d", &n, &r);
	for(int i = 1; i <= n; ++i) scanf("%d", &x[i]);
	for(int i = 1; i <= n; ++i) {
		y[i] = r;
		for(int j = 1; j < i; ++j) {
			if(abs(x[j] - x[i]) <= r * 2) {
				y[i] = max(y[i], calc(x[i] - x[j]) + y[j]);
			}
		}
	}
	for(int i = 1; i <= n; ++i) printf("%.9f%c", y[i], " \n"[i==n]);
	return 0;
}